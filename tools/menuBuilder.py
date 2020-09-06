import sys
import json

json_file = sys.argv[1]
output_file = open(sys.argv[2], 'w')

nodeCount = 0

def getMenus(tab, previous):
    global nodeCount

    nodeCount+=1

    current = "t"+str(nodeCount)

    output_file.write("{0} {1} = {0}(\"{2}\", &{3});\n".format(tab["type"], current, tab["name"], previous))
    
    if (len(tab["children"]) > 0):
        for child in tab["children"]:
            getMenus(child, current)

with open(json_file) as f:
    data = json.load(f)
    
    output_file.write("#ifndef GENERATEDMENU_HPP\n#define GENERATEDMENU_HPP\n")

    for lib in data[0]["libraries"]:
        output_file.write("#include \"{}\"\n".format(lib))


    output_file.write("ExitNode t0 = ExitNode(\"Exit?\");\n")
    getMenus(data[1], "t0")
    #Make a reference called head to t1

    output_file.write("Node* head = &t1;\n#endif")
    output_file.close()