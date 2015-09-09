#!/usr/bin/env python3

import re
import os
import fnmatch

def parse(filePath):
    fileHandleInput = open(filePath, "r")
    firstLine = fileHandleInput.readline().strip()
    if firstLine == "/*":
        currentLine = nextRelevantLine(fileHandleInput)
        match = re.match(r"(?:\s)*\*(?:\s)*Author: (.+)", currentLine)
        if match:
            author = match.group(1)
            fileHandleOutput.write("*Author:* " + author + "  \n")

        currentLine = nextRelevantLine(fileHandleInput)
        match = re.match(r"(?:\s)*\*(?:\s)*(.+)", currentLine)
        if match:
            description = match.group(1)
            fileHandleOutput.write("*Description:* " + description + "  \n")

        currentLine = nextRelevantLine(fileHandleInput)
        match = re.match(r"(?:\s)*\*(?:\s)*Arguments:", currentLine)
        if match:
            fileHandleOutput.write("*Arguments:*")
            currentLine = nextRelevantLine(fileHandleInput)
            match = re.match(r"(?:\s)*\*(?:\s)*(\d): (.+) <(\w+)>", currentLine)
            if match:
                while match:
                    argumentID = match.group(1)
                    argumentDescription = match.group(2)
                    argumentType = match.group(3)
                    fileHandleOutput.write("  \n- *"+ argumentType +  "*: " + argumentDescription + "")
                    currentLine = nextRelevantLine(fileHandleInput)
                    match = re.match(r"(?:\s)*\*(?:\s)*(\d): (.+) <(\w+)>", currentLine)
                fileHandleOutput.write("\n\n")
            elif re.match(r"(?:\s)*\*(?:\s)*None", currentLine):
                fileHandleOutput.write(" None  \n")
        else:
            fileHandleOutput.write("*Arguments:* None  \n")

        currentLine = nextRelevantLine(fileHandleInput)
        match = re.match(r"(?:\s)*\*(?:\s)*Return Value:", currentLine)
        if match:
            currentLine = nextRelevantLine(fileHandleInput)
            match = re.match(r"(?:\s)*\*(?:\s)*(.+) <(\w+)>", currentLine)
            if match:
                returnValueDescription = match.group(1)
                returnValueType = match.group(2)
                fileHandleOutput.write("*Return Value:* " + returnValueDescription + " (" + returnValueType + ")  \n")
            elif re.match(r"(?:\s)*\*(?:\s)*None", currentLine):
                fileHandleOutput.write("*Return Value:* None  \n")
        else:
            fileHandleOutput.write("*Return Value:* None  \n")

        currentLine = nextRelevantLine(fileHandleInput)
        match = re.match(r"(?:\s)*\*(?:\s)*Public: (.+)", currentLine)
        if match:
            fileHandleOutput.write("*Public:* " + match.group(1) + "  \n")
        else:
            fileHandleOutput.write("*Public:* No  \n")

        fileHandleOutput.write("\n")
        fileHandleInput.close()
    else:
        fileHandleInput.close()
        print(filePath.split('/')[-1] + ": Invalid file header.")
        return

def nextRelevantLine(fileHandle):
    line = fileHandle.readline()
    while line.strip() == "*":
        line = fileHandle.readline()
    return line

def main():
    global fileHandleOutput
    for subentry in os.listdir("../addons"):
        if os.path.isdir("../addons/" + subentry + "/functions"):
            fileHandleOutput = open("../documentation/functions/" + subentry + ".md", "w")
            fileHandleOutput.write("# " + subentry + " functions  \n\n")
            for root, dirnames, filenames in os.walk("../addons/" + subentry + "/functions"):
                for filename in fnmatch.filter(filenames, '*.sqf'):
                    fileHandleOutput.write("## " + subentry + "_" + filename[:-4] + "  \n")
                    parse("../addons/" + subentry + "/functions/" + filename)
            fileHandleOutput.close()

main()