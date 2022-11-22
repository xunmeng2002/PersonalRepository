#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

reload(sys)
sys.setdefaultencoding("utf-8-sig")
out_file = codecs.open("./Source/Dbo/DboDataStruct.cpp","w+","utf-8-sig")

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

out_file.write("#include \"DboDataStruct.h\"\n")
out_file.write("#include <string>\n")
out_file.write("\n")
out_file.write("thread_local char t_DataStringBuffer[10240];\n")
out_file.write("\n")
out_file.write("")
types = {}
formats = {}
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
    types[ get_attr(curr_node, "name")] = 'bool'
    
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
    types[ get_attr(curr_node, "name")] = 'int'
    
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
    types[ get_attr(curr_node, "name")] = 'int64'
    
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
    types[ get_attr(curr_node, "name")] = 'double'
    
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
    types[ get_attr(curr_node, "name")] = 'string'
    
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
    types[ get_attr(curr_node, "name")] = 'enum'
    
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
    types[ get_attr(curr_node, "name")] = 'datetime'
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("\n")
out_file.write("\n")
out_file.write("")
entry_name = "tables"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

pumpid = -1
parent2 = curr_node
for node2 in curr_node:
    curr_node = node2
    parent_map[curr_node] = parent2
    pumpid += 1
    tableName = "Dbo" +  get_attr(curr_node, "name")
    out_file.write("const char* ")
    out_file.write("%s" % str(tableName))
    out_file.write("::GetString() const\n")
    out_file.write("{\n")
    out_file.write("")
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("	sprintf(t_DataStringBuffer, \"")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        format = formats[ get_attr(curr_node, "type")]
        out_file.write("%s" % str(format))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write("\",\n")
    out_file.write("		")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        if types[ get_attr(curr_node, "type")] == 'enum':
            out_file.write("(char)")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("	return t_DataStringBuffer;\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("const char* ")
    out_file.write("%s" % str(tableName))
    out_file.write("::GetDebugString() const\n")
    out_file.write("{\n")
    out_file.write("")
    entry_name = "fields"
    parent3 = curr_node
    curr_node = curr_node.find(entry_name)
    parent_map[curr_node] = parent3
    
    out_file.write("	sprintf(t_DataStringBuffer, \"")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        format = formats[ get_attr(curr_node, "type")]
        out_file.write("%s" % get_attr(curr_node, "name"))
        out_file.write(":[")
        out_file.write("%s" % str(format))
        out_file.write("]")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write("\",\n")
    out_file.write("		")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        if types[ get_attr(curr_node, "type")] == 'enum':
            out_file.write("(char)")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("	return t_DataStringBuffer;\n")
    out_file.write("")
    
    curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("\n")
    out_file.write("")
    
if curr_node != parent2:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("\n")
out_file.write("")
out_file.close()
