#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

reload(sys)
sys.setdefaultencoding("utf-8-sig")
out_file = codecs.open("./source/Mdb/MdbEnumDict.cpp","w+","utf-8-sig")

tree = ET.parse("./model/Mdb/MdbEnumDict.xml")
curr_node = tree.getroot()
parent_map = {}
pumpidlist = []
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

out_file.write("#include \"MdbEnumDict.h\"\n")
out_file.write("\n")
out_file.write("\n")
out_file.write("")
entry_name = "enums"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

pumpidlist.append(0)
pumpid = -1
parent2 = curr_node
for node2 in curr_node:
    curr_node = node2
    parent_map[curr_node] = parent2
    pumpid += 1
    pumpidlist.append(pumpid)
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write(" ConvertTo")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("(const std::string& value)\n")
    out_file.write("{\n")
    out_file.write("	return (")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write(")value[0];\n")
    out_file.write("}\n")
    out_file.write("")
    
pumpidlist.pop()
if curr_node != parent2:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.write("\n")
out_file.write("")
out_file.close()
