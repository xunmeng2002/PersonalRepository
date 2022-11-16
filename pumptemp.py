#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

reload(sys)
sys.setdefaultencoding("utf-8-sig")
out_file = codecs.open("./source/Mdb/MdbTables.cpp","w+","utf-8-sig")

curr_node = ET.Element("root")
curr_node.append(ET.parse("./model/Mdb/Mdb.xml").getroot())
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

out_file.write("#ifdef _MSC_VER\n")
out_file.write("#pragma warning(disable : 26495)\n")
out_file.write("#endif\n")
out_file.write("\n")
out_file.write("#include \"MdbTables.h\"\n")
out_file.write("#include \"Mdb.h\"\n")
out_file.write("\n")
out_file.write("")
formatSymbols = {}
formatSymbols["string"] = "s"
formatSymbols["int"] = "d"
formatSymbols["double"] = "f"
formatSymbols["enum"] = "d"
out_file.write("\n")
out_file.write("")
entry_name = "mdb"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

entry_name = "tables"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    out_file.write("int ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("::ToStream(char* buff, int size) const\n")
    out_file.write("{\n")
    out_file.write("")
    entry_name = "items"
    parent4 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent4
    
    out_file.write("	return snprintf(buff, size, \"")
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write(" ")
        itemType=formatSymbols[ get_attr(curr_node, "type")]
        out_file.write("'%")
        out_file.write("%s" % str(itemType))
        out_file.write("'")
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    out_file.write("\",\n")
    out_file.write("		")
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        if  get_attr(curr_node, "type") == "string":
            out_file.write(".c_str()")
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("int ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("::ToString(char* buff, int size) const\n")
    out_file.write("{\n")
    out_file.write("")
    entry_name = "items"
    parent4 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent4
    
    out_file.write("	return snprintf(buff, size, \"Mdb")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write(": ")
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        itemType=formatSymbols[ get_attr(curr_node, "type")]
        out_file.write(":[%")
        out_file.write("%s" % str(itemType))
        out_file.write("]")
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    out_file.write("\",\n")
    out_file.write("		")
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        if  get_attr(curr_node, "type") == "string":
            out_file.write(".c_str()")
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("string ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("::CreateSql()\n")
    out_file.write("{\n")
    out_file.write("	return \"CREATE TABLE IF NOT EXISTS t_Mdb")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("(")
    entry_name = "items"
    parent4 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent4
    
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(" char(")
        out_file.write("%s" % get_attr(curr_node, "len"))
        out_file.write("), ")
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    entry_name = "primarykey"
    parent4 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent4
    
    out_file.write("PRIMARY KEY(")
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    out_file.write("));\";\n")
    out_file.write("}\n")
    out_file.write("string ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("::InsertSql()\n")
    out_file.write("{\n")
    out_file.write("	::memset(m_Buff, 0, sizeof(m_Buff));\n")
    out_file.write("	ToStream(m_Buff, 4096);\n")
    out_file.write("	return \"REPLACE INTO t_Mdb")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write(" VALUES(\" + string(m_Buff) + \");\";\n")
    out_file.write("}\n")
    out_file.write("int ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("::OnSelectCallback(void* callback, int colCount, char** colValues, char** colNames)\n")
    out_file.write("{\n")
    out_file.write("	auto field = new ")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("();\n")
    out_file.write("")
    entry_name = "items"
    parent4 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent4
    
    pumpid = -1
    parent5 = curr_node
    for node5 in curr_node:
        curr_node = node5
        parent_map[curr_node] = parent5
        pumpid += 1
        if  get_attr(curr_node, "type") == 'enum':
            out_file.write("	field->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = ConvertTo")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write("(colValues[")
            out_file.write("%s" % str(pumpid))
            out_file.write("]);\n")
            out_file.write("")
        elif  get_attr(curr_node, "type") == 'int':
            out_file.write("	field->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = atoi(colValues[")
            out_file.write("%s" % str(pumpid))
            out_file.write("]);\n")
            out_file.write("")
        elif  get_attr(curr_node, "type") == 'double':
            out_file.write("	field->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = atof(colValues[")
            out_file.write("%s" % str(pumpid))
            out_file.write("]);\n")
            out_file.write("")
        else:
            out_file.write("	field->")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(" = colValues[")
            out_file.write("%s" % str(pumpid))
            out_file.write("];\n")
            out_file.write("")
        
    if curr_node != parent5:
        curr_node = parent_map[curr_node]
    
    curr_node = parent_map[curr_node]
    out_file.write("\n")
    out_file.write("	((MdbCallback*)callback)->SelectMdb")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("Callback(field);\n")
    out_file.write("	return 0;\n")
    out_file.write("}\n")
    out_file.write("\n")
    out_file.write("")
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.close()
