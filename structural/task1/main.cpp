#include <string>
#include <iostream>
#include <execution>
#include <algorithm>
/*
*/
class Text{
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};

class DecoratedText: public Text{
public:
    explicit DecoratedText(Text* text): text_(text) {}
    virtual ~DecoratedText()= default;
    Text* text_;
};

class ItalicText: public DecoratedText {
public:
    explicit ItalicText(Text* text): DecoratedText(text) {}
    void render(const std::string& data) const override{
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText: public DecoratedText {
public:
    explicit BoldText(Text* text): DecoratedText(text) {}
    void render(const std::string& data) const override{
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph: public DecoratedText{
public:
    explicit Paragraph(Text* text): DecoratedText(text) {}
    void render(const std::string& data) const override{
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed: public DecoratedText{
public:
    explicit Reversed(Text* text): DecoratedText(text) {}
    void render(const std::string& data) const override{
        std::string temp = data;
        std::reverse(std::execution::seq, temp.begin(), temp.end());
        text_->render(temp);
    }
};

class Link: public DecoratedText{
public:
    explicit Link(Text* text): DecoratedText(text) {}
    void render(const std::string& data, const std::string& data2) const{
        std::cout << "<a href=";
        text_->render(data);
        std::cout << ">";
        text_->render(data2);
        std::cout << "</a>";
    }
};

int main() {
    auto text_block1 = new Paragraph(new Text());
    auto text_block2 = new Reversed(new Text());
    auto text_block3 = new Link(new Text());

    text_block1->render("Hello world");
    std::cout<< std::endl;

    text_block2->render("Hello world");
    std::cout<< std::endl;

    text_block3->render("netology.ru", "Hello world");
    std::cout<< std::endl;

    delete text_block1;
    delete text_block2;
    delete text_block3;
    return 0;
}
