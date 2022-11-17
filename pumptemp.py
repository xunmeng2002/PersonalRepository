#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

reload(sys)
sys.setdefaultencoding("utf-8-sig")
out_file = codecs.open("./Source/Dbo/Dbo.cpp","w+","utf-8-sig")

curr_node = ET.Element("root")
curr_node.append(ET.parse("./Model/Dbo/TradeTables.xml").getroot())
curr_node.append(ET.parse("./Model/Dbo/DataType.xml").getroot())
parent_map = {}
def get_attr(node, name):
    while node != None:
        if node.get(name) == None:
            if node in parent_map:
                node = parent_map[node]
            else:
                break
        else:
            return node.get(name)
    return ""

out_file.write("#pragma warning(disable: 4311)\n")
out_file.write("#include \"Dbo.h\"\n")
out_file.write("#include <string.h>\n")
out_file.write("\n")
out_file.write("")
formats = {}
dataTypes = {}
entry_name = "types"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

entry_name = "bools"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%d'
    dataTypes[ get_attr(curr_node, "name")] = 'bool'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
entry_name = "ints"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%d'
    dataTypes[ get_attr(curr_node, "name")] = 'int'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
entry_name = "int64s"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%lld'
    dataTypes[ get_attr(curr_node, "name")] = 'int64'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
entry_name = "doubles"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%f'
    dataTypes[ get_attr(curr_node, "name")] = 'double'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
entry_name = "strings"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%s'
    dataTypes[ get_attr(curr_node, "name")] = 'string'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
entry_name = "enums"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%c'
    dataTypes[ get_attr(curr_node, "name")] = 'enum'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
entry_name = "datetimes"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    formats[ get_attr(curr_node, "name")] = '%s'
    dataTypes[ get_attr(curr_node, "name")] = 'string'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("\n")
out_file.write("")
entry_name = "tables"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

out_file.write("Dbo::Dbo(const std::string& host, const std::string& user, const std::string& passwd)\n")
out_file.write("{\n")
out_file.write("	m_Sql = new char[4096];\n")
out_file.write("	m_Host = host;\n")
out_file.write("	m_User = user;\n")
out_file.write("	m_Passwd = passwd;\n")
out_file.write("\n")
out_file.write("	m_Driver = sql::mysql::get_driver_instance();\n")
out_file.write("	m_DBConnection = m_Driver->connect(host, user, passwd);\n")
out_file.write("\n")
out_file.write("")
pumpid = -1
parent2 = curr_node
for node2 in curr_node:
    curr_node = node2
    parent_map[curr_node] = parent2
    pumpid += 1
    className = "Dbo" +  get_attr(curr_node, "name")
    out_file.write("	m_")
    out_file.write("%s" % str(className))
    out_file.write("InsertStatement = nullptr;\n")
    out_file.write("	m_")
    out_file.write("%s" % str(className))
    out_file.write("TruncateStatement = nullptr;\n")
    out_file.write("	m_")
    out_file.write("%s" % str(className))
    out_file.write("DeleteStatement = nullptr;\n")
    out_file.write("	m_")
    out_file.write("%s" % str(className))
    out_file.write("UpdateStatement = nullptr;\n")
    out_file.write("	m_")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKeyStatement = nullptr;\n")
    out_file.write("")
    entry_name = "uniquekeys"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write("	m_")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKeyStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" = nullptr;\n")
        out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    entry_name = "indexes"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write("	m_")
        out_file.write("%s" % str(className))
        out_file.write("IndexStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" = nullptr;\n")
        out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    
if curr_node != parent2:
    curr_node = parent_map[curr_node]
out_file.write("}\n")
out_file.write("Dbo::~Dbo()\n")
out_file.write("{\n")
out_file.write("	delete[] m_Sql;\n")
out_file.write("}\n")
out_file.write("\n")
out_file.write("")
pumpid = -1
parent2 = curr_node
for node2 in curr_node:
    curr_node = node2
    parent_map[curr_node] = parent2
    pumpid += 1
    className = "Dbo" +  get_attr(curr_node, "name")
    tableName = "t_" +  get_attr(curr_node, "name")
    fieldTypeNames = {}
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        fieldTypeNames[ get_attr(curr_node, "name")] =  get_attr(curr_node, "type")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    out_file.write("\n")
    out_file.write("")
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("bool Dbo::Insert")
    out_file.write("%s" % str(className))
    out_file.write("(")
    out_file.write("%s" % str(className))
    out_file.write("* record)\n")
    out_file.write("{\n")
    out_file.write("	if (m_")
    out_file.write("%s" % str(className))
    out_file.write("InsertStatement == nullptr)\n")
    out_file.write("	{\n")
    out_file.write("		m_")
    out_file.write("%s" % str(className))
    out_file.write("InsertStatement = m_DBConnection->prepareStatement(\"insert into ")
    out_file.write("%s" % str(tableName))
    out_file.write(" Values(")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("?")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\");\n")
    out_file.write("	}\n")
    out_file.write("	SetStatementFor")
    out_file.write("%s" % str(className))
    out_file.write("Record(m_")
    out_file.write("%s" % str(className))
    out_file.write("InsertStatement, record);\n")
    out_file.write("	return m_")
    out_file.write("%s" % str(className))
    out_file.write("InsertStatement->execute();\n")
    out_file.write("}\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    out_file.write("bool Dbo::Truncate")
    out_file.write("%s" % str(className))
    out_file.write("()\n")
    out_file.write("{\n")
    out_file.write("	if(m_")
    out_file.write("%s" % str(className))
    out_file.write("TruncateStatement == nullptr)\n")
    out_file.write("	{\n")
    out_file.write("		m_")
    out_file.write("%s" % str(className))
    out_file.write("TruncateStatement = m_DBConnection->prepareStatement(\"truncate  table ")
    out_file.write("%s" % str(tableName))
    out_file.write(" ;\");\n")
    out_file.write("	}\n")
    out_file.write("	return m_")
    out_file.write("%s" % str(className))
    out_file.write("TruncateStatement->execute();\n")
    out_file.write("}\n")
    out_file.write("")
    entry_name = "primarykey"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("bool Dbo::Delete")
    out_file.write("%s" % str(className))
    out_file.write("(")
    out_file.write("%s" % str(className))
    out_file.write("* record)\n")
    out_file.write("{\n")
    out_file.write("	if (m_")
    out_file.write("%s" % str(className))
    out_file.write("DeleteStatement == nullptr)\n")
    out_file.write("	{\n")
    out_file.write("		m_")
    out_file.write("%s" % str(className))
    out_file.write("DeleteStatement = m_DBConnection->prepareStatement(\"delete from ")
    out_file.write("%s" % str(tableName))
    out_file.write(" where ")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(" and ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" = ?")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(";\");\n")
    out_file.write("	}\n")
    out_file.write("	SetStatementFor")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKey(m_")
    out_file.write("%s" % str(className))
    out_file.write("DeleteStatement")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write(", record->")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("	return m_")
    out_file.write("%s" % str(className))
    out_file.write("DeleteStatement->execute();\n")
    out_file.write("}\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("bool Dbo::Update")
    out_file.write("%s" % str(className))
    out_file.write("(")
    out_file.write("%s" % str(className))
    out_file.write("* record)\n")
    out_file.write("{\n")
    out_file.write("	if (m_")
    out_file.write("%s" % str(className))
    out_file.write("UpdateStatement == nullptr)\n")
    out_file.write("	{\n")
    out_file.write("		m_")
    out_file.write("%s" % str(className))
    out_file.write("UpdateStatement = m_DBConnection->prepareStatement(\"replace into ")
    out_file.write("%s" % str(tableName))
    out_file.write(" Values(")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("?")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\");\n")
    out_file.write("	}\n")
    out_file.write("	SetStatementFor")
    out_file.write("%s" % str(className))
    out_file.write("Record(m_")
    out_file.write("%s" % str(className))
    out_file.write("UpdateStatement, record);\n")
    out_file.write("	return m_")
    out_file.write("%s" % str(className))
    out_file.write("UpdateStatement->execute();\n")
    out_file.write("}\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    entry_name = "primarykey"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("%s" % str(className))
    out_file.write("* Dbo::Query")
    out_file.write("%s" % str(className))
    out_file.write("FromPrimaryKey(")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("const C")
        out_file.write("%s" % str(fieldTypeName))
        out_file.write("Type& ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(")\n")
    out_file.write("{\n")
    out_file.write("	if (m_")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKeyStatement == nullptr)\n")
    out_file.write("	{\n")
    out_file.write("		m_")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKeyStatement = m_DBConnection->prepareStatement(\"select * from ")
    out_file.write("%s" % str(tableName))
    out_file.write(" where ")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(" and ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" = ?")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(";\");\n")
    out_file.write("	}\n")
    out_file.write("	SetStatementFor")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKey(m_")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKeyStatement")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write(", ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("	auto result = m_")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKeyStatement->executeQuery();\n")
    out_file.write("	if (result->next())\n")
    out_file.write("	{\n")
    out_file.write("		return Get")
    out_file.write("%s" % str(className))
    out_file.write("Record(result);\n")
    out_file.write("	}\n")
    out_file.write("	return nullptr;\n")
    out_file.write("}\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    entry_name = "uniquekeys"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write("%s" % str(className))
        out_file.write("* Dbo::Query")
        out_file.write("%s" % str(className))
        out_file.write("FromUniqueKey")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("(")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
            if pumpid > 0:
                out_file.write(", ")
            out_file.write("const C")
            out_file.write("%s" % str(fieldTypeName))
            out_file.write("Type& ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(")\n")
        out_file.write("{\n")
        out_file.write("	if (m_")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKeyStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" == nullptr)\n")
        out_file.write("	{\n")
        out_file.write("		m_")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKeyStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" = m_DBConnection->prepareStatement(\"select * from ")
        out_file.write("%s" % str(tableName))
        out_file.write(" where ")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            if pumpid > 0:
                out_file.write(" and ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = ?")
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(";\");\n")
        out_file.write("	}\n")
        out_file.write("	SetStatementFor")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKey")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("(m_")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKeyStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(");\n")
        out_file.write("	auto result = m_")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKeyStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("->executeQuery();\n")
        out_file.write("	if (result->next())\n")
        out_file.write("	{\n")
        out_file.write("		return Get")
        out_file.write("%s" % str(className))
        out_file.write("Record(result);\n")
        out_file.write("	}\n")
        out_file.write("	return nullptr;\n")
        out_file.write("}\n")
        out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    entry_name = "indexes"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write("void Dbo::Query")
        out_file.write("%s" % str(className))
        out_file.write("FromIndex")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("(std::vector<")
        out_file.write("%s" % str(className))
        out_file.write("*>& records")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
            out_file.write(", const C")
            out_file.write("%s" % str(fieldTypeName))
            out_file.write("Type& ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(")\n")
        out_file.write("{\n")
        out_file.write("	if (m_")
        out_file.write("%s" % str(className))
        out_file.write("IndexStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" == nullptr)\n")
        out_file.write("	{\n")
        out_file.write("		m_")
        out_file.write("%s" % str(className))
        out_file.write("IndexStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" = m_DBConnection->prepareStatement(\"select * from ")
        out_file.write("%s" % str(tableName))
        out_file.write(" where ")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            if pumpid > 0:
                out_file.write(" and ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = ?")
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(";\");\n")
        out_file.write("	}\n")
        out_file.write("	SetStatementFor")
        out_file.write("%s" % str(className))
        out_file.write("Index")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("(m_")
        out_file.write("%s" % str(className))
        out_file.write("IndexStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(");\n")
        out_file.write("	auto result = m_")
        out_file.write("%s" % str(className))
        out_file.write("IndexStatement")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("->executeQuery();\n")
        out_file.write("	while (result->next())\n")
        out_file.write("	{\n")
        out_file.write("		auto record = Get")
        out_file.write("%s" % str(className))
        out_file.write("Record(result);\n")
        out_file.write("		records.push_back(record);\n")
        out_file.write("	}\n")
        out_file.write("}\n")
        out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("void Dbo::SetStatementFor")
    out_file.write("%s" % str(className))
    out_file.write("Record(sql::PreparedStatement* statement, ")
    out_file.write("%s" % str(className))
    out_file.write("* record)\n")
    out_file.write("{\n")
    out_file.write("")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        index = pumpid + 1
        dataType = dataTypes[ get_attr(curr_node, "type")]
        if dataType == 'bool':
            out_file.write("	statement->setBoolean(")
            out_file.write("%s" % str(index))
            out_file.write(", record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'int':
            out_file.write("	statement->setInt(")
            out_file.write("%s" % str(index))
            out_file.write(", record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'int64':
            out_file.write("	statement->setInt64(")
            out_file.write("%s" % str(index))
            out_file.write(", record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'double':
            out_file.write("	statement->setDouble(")
            out_file.write("%s" % str(index))
            out_file.write(", record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'string':
            out_file.write("	statement->setString(")
            out_file.write("%s" % str(index))
            out_file.write(", record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'enum':
            out_file.write("	statement->setInt(")
            out_file.write("%s" % str(index))
            out_file.write(", int(record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write("));\n")
            out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    entry_name = "primarykey"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("void Dbo::SetStatementFor")
    out_file.write("%s" % str(className))
    out_file.write("PrimaryKey(sql::PreparedStatement* statement")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
        out_file.write(", const C")
        out_file.write("%s" % str(fieldTypeName))
        out_file.write("Type& ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(")\n")
    out_file.write("{\n")
    out_file.write("")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        index = pumpid + 1
        fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
        dataType = dataTypes[fieldTypeName]
        if dataType == 'bool':
            out_file.write("	statement->setBoolean(")
            out_file.write("%s" % str(index))
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'int':
            out_file.write("	statement->setInt(")
            out_file.write("%s" % str(index))
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'int64':
            out_file.write("	statement->setInt64(")
            out_file.write("%s" % str(index))
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'double':
            out_file.write("	statement->setDouble(")
            out_file.write("%s" % str(index))
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'string':
            out_file.write("	statement->setString(")
            out_file.write("%s" % str(index))
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'enum':
            out_file.write("	statement->setInt(")
            out_file.write("%s" % str(index))
            out_file.write(", int(")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write("));\n")
            out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    entry_name = "uniquekeys"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write("void Dbo::SetStatementFor")
        out_file.write("%s" % str(className))
        out_file.write("UniqueKey")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("(sql::PreparedStatement* statement")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
            out_file.write(", const C")
            out_file.write("%s" % str(fieldTypeName))
            out_file.write("Type& ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(")\n")
        out_file.write("{\n")
        out_file.write("")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            index = pumpid + 1
            fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
            dataType = dataTypes[fieldTypeName]
            if dataType == 'bool':
                out_file.write("	statement->setBoolean(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'int':
                out_file.write("	statement->setInt(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'int64':
                out_file.write("	statement->setInt64(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'double':
                out_file.write("	statement->setDouble(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'string':
                out_file.write("	statement->setString(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'enum':
                out_file.write("	statement->setInt(")
                out_file.write("%s" % str(index))
                out_file.write(", int(")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write("));\n")
                out_file.write("")
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write("}\n")
        out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    entry_name = "indexes"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        out_file.write("void Dbo::SetStatementFor")
        out_file.write("%s" % str(className))
        out_file.write("Index")
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write("(sql::PreparedStatement* statement")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
            out_file.write(", const C")
            out_file.write("%s" % str(fieldTypeName))
            out_file.write("Type& ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write(")\n")
        out_file.write("{\n")
        out_file.write("")
        pumpid = -1
        parent5 = curr_node
        for node5 in curr_node:
            curr_node = node5
            parent_map[curr_node] = parent5
            pumpid += 1
            index = pumpid + 1
            fieldTypeName = fieldTypeNames[ get_attr(curr_node, "name")]
            dataType = dataTypes[fieldTypeName]
            if dataType == 'bool':
                out_file.write("	statement->setBoolean(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'int':
                out_file.write("	statement->setInt(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'int64':
                out_file.write("	statement->setInt64(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'double':
                out_file.write("	statement->setDouble(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'string':
                out_file.write("	statement->setString(")
                out_file.write("%s" % str(index))
                out_file.write(", ")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write(");\n")
                out_file.write("")
            if dataType == 'enum':
                out_file.write("	statement->setInt(")
                out_file.write("%s" % str(index))
                out_file.write(", int(")
                out_file.write("%s" % get_attr(curr_node, "name"))
                out_file.write("));\n")
                out_file.write("")
            
        if curr_node != parent5:
            curr_node = parent_map[curr_node]
        out_file.write("}\n")
        out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    out_file.write("%s" % str(className))
    out_file.write("* Dbo::Get")
    out_file.write("%s" % str(className))
    out_file.write("Record(sql::ResultSet* result)\n")
    out_file.write("{\n")
    out_file.write("	")
    out_file.write("%s" % str(className))
    out_file.write("* record = new ")
    out_file.write("%s" % str(className))
    out_file.write("();\n")
    out_file.write("")
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        index = pumpid + 1
        dataType = dataTypes[ get_attr(curr_node, "type")]
        if dataType == 'bool':
            out_file.write("	record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = result->getBoolean(")
            out_file.write("%s" % str(index))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'int':
            out_file.write("	record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = result->getInt(")
            out_file.write("%s" % str(index))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'int64':
            out_file.write("	record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = result->getInt64(")
            out_file.write("%s" % str(index))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'double':
            out_file.write("	record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = result->getDouble(")
            out_file.write("%s" % str(index))
            out_file.write(");\n")
            out_file.write("")
        if dataType == 'string':
            out_file.write("	strcpy(record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(", result->getString(")
            out_file.write("%s" % str(index))
            out_file.write(").c_str());\n")
            out_file.write("")
        if dataType == 'enum':
            out_file.write("	record->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = C")
            out_file.write("%s" % get_attr(curr_node, "type"))
            out_file.write("Type(result->getInt(")
            out_file.write("%s" % str(index))
            out_file.write("));\n")
            out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    out_file.write("	return record;\n")
    out_file.write("}\n")
    out_file.write("\n")
    out_file.write("")
    
if curr_node != parent2:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.close()
