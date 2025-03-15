#ifndef SQL_QUERY_BUILDER_H
#define SQL_QUERY_BUILDER_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <map>
/*
*/
struct SelectQuery
{
    std::string _table;
    std::string _selectFull;
//    std::string _select; //task1
    std::vector<std::string> _select;
//    std::deque<std::string> _where; //task1
    std::map<std::string, std::string> _where;
};

class SqlSelectQueryBuilder
{
public:
//    SqlSelectQueryBuilder &addColumn(const std::string &column); //task1
    SqlSelectQueryBuilder& addColumns(
            const std::vector<std::string>& columns) noexcept; //task2

    SqlSelectQueryBuilder &addFrom( const std::string &table);

//    SqlSelectQueryBuilder &addWhere( const std::string &whereLeft,
//                                     const std::string &whereRight); //task1
    SqlSelectQueryBuilder& addWhere(
            const std::map<std::string, std::string>& kv) noexcept;  //task2

    std::string&  buildQuery(void);
    explicit SqlSelectQueryBuilder();
    ~SqlSelectQueryBuilder()= default;
private:
    std::shared_ptr<SelectQuery> selectQ;
};

#endif // SQL_QUERY_BUILDER_H
