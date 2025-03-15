#include "sql_query_builder.h"
/*
*/
SqlSelectQueryBuilder &SqlSelectQueryBuilder
    ::addFrom(const std::string &table){
    selectQ->_table= table;
    return *this;
}

/*-task1-*/
//SqlSelectQueryBuilder &SqlSelectQueryBuilder
//    ::addColumn(const std::string &column){
//    if(selectQ->_select== "SELECT *"){
//        selectQ->_select = "SELECT "+column;
//    } else{
//        selectQ->_select+= ", "+column;
//    }
//    return *this;
//}

//SqlSelectQueryBuilder &SqlSelectQueryBuilder
//    ::addWhere(const std::string &whereLeft, const std::string &whereRight){
//    selectQ->_where.push_back( whereLeft+"="+whereRight);
//    return *this;
//}

//std::string &SqlSelectQueryBuilder::buildQuery(){
//    selectQ->_select+= " FROM " + selectQ->_table;
//    if(!(selectQ->_where.empty())){
//        selectQ->_select+= " WHERE "+ selectQ->_where.front();
//        selectQ->_where.pop_front();
//    }
//    if(!(selectQ->_where.empty())){
//        selectQ->_select+= " AND "+ selectQ->_where.front();
//        selectQ->_where.pop_front();
//    }
//    selectQ->_select+= ";";
//    return selectQ->_select;
//}

//SqlSelectQueryBuilder::SqlSelectQueryBuilder(){
//    selectQ= std::make_unique<SelectQuery>();
//    selectQ->_select= "SELECT *";
//}

/*-task2-*/
SqlSelectQueryBuilder &SqlSelectQueryBuilder
    ::addColumns(const std::vector<std::string> &columns) noexcept{
    if(selectQ->_select.size()==1){
        selectQ->_select[0] = "SELECT ";
    }
    for(auto& v: columns)
        selectQ->_select.push_back(v);
    return *this;
}

SqlSelectQueryBuilder &SqlSelectQueryBuilder
    ::addWhere(const std::map<std::string, std::string> &kv) noexcept{
    selectQ->_where= kv;
    return *this;
}

std::string &SqlSelectQueryBuilder::buildQuery(){
    selectQ->_select.emplace_back(" FROM " + selectQ->_table);
    if(!(selectQ->_where.empty()))
        selectQ->_select.emplace_back(" WHERE " + selectQ->_where["id"]
                                    + " AND "   + selectQ->_where["name"]);
    selectQ->_select.emplace_back(";");
    for(auto& v: selectQ->_select)
        selectQ->_selectFull += v;
    return selectQ->_selectFull;
}

SqlSelectQueryBuilder::SqlSelectQueryBuilder(){
    selectQ= std::make_unique<SelectQuery>();
    selectQ->_select.push_back( "SELECT *");
}
