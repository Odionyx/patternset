#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <exception>

class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        } else {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};

class TestDB : VeryHeavyDatabase {
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) noexcept {
        return "test_data\n";
    }
private:
    VeryHeavyDatabase* real_db_;
};

class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots=1)
        : real_db_(real_object), _shots(shots){
    }
    std::string GetData(const std::string& key) noexcept {
        return ((_shots--)? "value": "error");
    }
private:
    VeryHeavyDatabase* real_db_;
    size_t _shots;
};

int main( int argc, char** argv) {
    try {
        auto real_db = VeryHeavyDatabase();
        auto cached_db = CacheProxyDB(std::addressof(real_db));
        auto test_db = TestDB(std::addressof(real_db));
        auto limit_db = OneShotDB(std::addressof(real_db), 2);
        std::cout << cached_db.GetData("key") << std::endl;
        std::cout << cached_db.GetData("key") << std::endl;
        std::cout << test_db.GetData("key") << std::endl;

        std::cout << limit_db.GetData("key") << std::endl;
        std::cout << limit_db.GetData("key") << std::endl;
        std::cout << limit_db.GetData("key") << std::endl;
    } catch( const std::exception& e){
        std::cerr<< e.what()<< std::endl;
    } catch(...){
        std::cerr<< __FUNCTION__<< std::endl;
    }
    return 0;
}
