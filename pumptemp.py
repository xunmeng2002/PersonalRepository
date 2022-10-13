#coding:utf-8
import xml.etree.cElementTree as ET
import codecs,sys

reload(sys)
sys.setdefaultencoding("utf-8-sig")
out_file = codecs.open("./Source/Ctp/6.5.1/ThostFtdcTraderSpiMiddle.cpp","w+","utf-8-sig")

curr_node = ET.Element("root")
curr_node.append(ET.parse("./Libs/CTP/CtpApiModel_6.5.1.xml").getroot())
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

out_file.write("#include \"ThostFtdcTraderSpiMiddle.h\"\n")
out_file.write("#include \"Logger.h\"\n")
out_file.write("#include \"StructWriteLogFunc.h\"\n")
out_file.write("\n")
out_file.write("\n")
out_file.write("")
types={}
types['bool']='d'
types['char']='c'
types['short']='d'
types['int']='d'
types['double']='f'
types['string']='s'
out_file.write("\n")
out_file.write("")
entry_name = "ctp"
parent1 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent1

entry_name = "spi"
parent2 = curr_node
curr_node = curr_node.find(entry_name)
parent_map[curr_node] = parent2

pumpid = -1
parent3 = curr_node
for node3 in curr_node:
    curr_node = node3
    parent_map[curr_node] = parent3
    pumpid += 1
    out_file.write("void CThostFtdcTraderSpiMiddle::")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write("(")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if pumpid > 0:
            out_file.write(", ")
        out_file.write("%s" % get_attr(curr_node, "type"))
        out_file.write(" ")
        if  get_attr(curr_node, "custom") == "True":
            out_file.write("*p")
        out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(")\n")
    out_file.write("{\n")
    out_file.write("	WRITE_LOG(LogLevel::Info, \"")
    out_file.write("%s" % get_attr(curr_node, "name"))
    out_file.write(":")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if  get_attr(curr_node, "custom") == "False":
            currType=types[ get_attr(curr_node, "basetype")]
            out_file.write(" ")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write("[%")
            out_file.write("%s" % str(currType))
            out_file.write("]")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write("\"")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if  get_attr(curr_node, "custom") == "False":
            out_file.write(", ")
            out_file.write("%s" % get_attr(curr_node, "name"))
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write(");\n")
    out_file.write("")
    pumpid = -1
    parent4 = curr_node
    for node4 in curr_node:
        curr_node = node4
        parent_map[curr_node] = parent4
        pumpid += 1
        if  get_attr(curr_node, "custom") == "True":
            out_file.write("	Write")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write("(p")
            out_file.write("%s" % get_attr(curr_node, "name"))
            out_file.write(");\n")
            out_file.write("")
        
    if curr_node != parent4:
        curr_node = parent_map[curr_node]
    out_file.write("}\n")
    out_file.write("\n")
    out_file.write("")
    
if curr_node != parent3:
    curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]

curr_node = parent_map[curr_node]
out_file.close()
