# O S P R E Y
import os
import sys
import shutil

codefile = "nds/code.c"
file_contents = ""

print("OSPREY v0.2a")

buildfile  = input("file path: ")


if ('DEVKITARM' in os.environ == False):
    print("DevkitArm is not installed")
    sys.exit()

devkitpro = os.environ['DEVKITPRO']
if (os.path.isdir(devkitpro+'calico') == False):
    print("WARNING: THIS PROJECT IS ONLY COMPATIBLE WITH LIBNDS >= v2.0\n")

if os.path.exists(codefile):
    os.remove(codefile)

#with open(buildfile, 'r') as file:
#            file_contents = file.read()
with open(buildfile, 'r') as file:
    for line in file:
        #print(line.strip())
        file_contents+=('"'+line.replace("\n", "")+"\\"+"n"+'"\n')


f = open(codefile, "x")
f.write('static const char *osprey_file =\n'+file_contents+';')
f.close()


os.system("cd nds && make")



shutil.copyfile("nds/build/firmware.nds", "osprey.nds")
