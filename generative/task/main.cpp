#include "sql_query_builder.h"
/*
*/
int main( int argc, char** argv)
{
    //std::cout << "Hello World!" << std::endl;
    SqlSelectQueryBuilder qb;
//task1
//    qb.addWhere("id", "42").addWhere("name", "John");
//    qb.addColumn("name").addColumn("phone");

    qb.addFrom("students");
//task2
    std::vector<std::string> vec{"name, ","phone"};
    std::map<std::string, std::string> where;
    where["id"]=    "id=42";
    where["name"]=  "name=John";
    qb.addWhere(where);
    qb.addColumns(vec);

    std::cout<< qb.buildQuery()<< std::endl;

    return 0;
}
