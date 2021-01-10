#!/bin/sh

# Fixed paths
PYTHON="/usr/bin/python"

PATH_OPEN62541="/home/pi/open62541/open62541"
PATH_UA_NODESET="$PATH_OPEN62541/examples/sentenz/sc/model/ua-nodeset"
PATH_TOOLS="$PATH_OPEN62541/tools"
SRC_GENERATED="/$PATH_OPEN62541/examples/sentenz/sc/model/generate"

# Need to be changed
CS_NODESET="DI"
PATH_SRC_GENERATED="$SRC_GENERATED/$CS_NODESET"

# Note NS0 (UA) and NS1 (DI) are currently created by open62541 wirh the amalgation flag
#
# Model_DI
FILE_XML_MODEL_NS4="Opc_Ua.Di_Model.xml"
NAME_NAMESPACE_MODEL_NS4="namespace_di_model_generated"

# 
# Statuscode
#  Note: With Amalgation flag already included.
#echo "Generate statuscode descriptions by generate_statuscode_descriptions.py\n"
#$PYTHON $PATH_TOOLS/generate_statuscode_descriptions.py $PATH_UA_NODESET/Schema/StatusCode.csv $PATH_SRC_GENERATED/statuscodes

# 
# Node Id
# 

# NS0 NodeID
#  Note: With Amalgation flag already included.
#echo "Generate nodeid header NS0 NodeID by generate_nodeid_header.py\n"
#$PYTHON $PATH_TOOLS/generate_nodeid_header.py $PATH_UA_NODESET/Schema/NodeIds.csv $PATH_SRC_GENERATED/nodeids NS0

# DI NodeID
echo "Generate nodeid header DI NodeID by generate_nodeid_header.py\n"
$PYTHON $PATH_TOOLS/generate_nodeid_header.py $PATH_UA_NODESET/DI/OpcUaDiModel.csv $PATH_SRC_GENERATED/di_nodeids DI

# 
# Datatypes
# 

# Generate Datatype NS1
#  Note: With Amalgation flag already included.
#echo "Generate datatypes UA NS0 by generate_datatypes.py\n"
#$PYTHON $PATH_TOOLS/generate_datatypes.py --namespace=0 --type-bsd=$PATH_UA_NODESET/Schema/Opc.Ua.Types.bsd --type-csv=$PATH_UA_NODESET/Schema/NodeIds.csv $PATH_SRC_GENERATED/types

# Generate Datatype NS1
echo "Generate datatypes DI NS1 by generate_datatypes.py\n"
$PYTHON $PATH_TOOLS/generate_datatypes.py --namespace=2 --type-bsd=$PATH_UA_NODESET/DI/Opc.Ua.Di.Types.bsd --type-csv=$PATH_UA_NODESET/DI/OpcUaDiModel.csv --no-builtin $PATH_SRC_GENERATED/types_di

# 
# Nodeset Comiler
# 

# Compile NS0 UA
#echo "\nNodeset_compiler UA NS0 by nodeset_compiler.py\n"
#  Note: With Amalgation flag already included.
#$PYTHON $PATH_TOOLS/nodeset_compiler/nodeset_compiler.py --internal-headers --ignore=$PATH_TOOLS/nodeset_compiler/NodeID_NS0_Base.txt --xml=$PATH_UA_NODESET/Schema/Opc.Ua.NodeSet2.xml $PATH_SRC_GENERATED/namespace0_generated

# Compile NS1 DI
echo "\nNodeset_compiler DI NS1 by nodeset_compiler.py\n"
$PYTHON $PATH_TOOLS/nodeset_compiler/nodeset_compiler.py --internal-headers --types-array=UA_TYPES --types-array=UA_TYPES_DI --existing=$PATH_UA_NODESET/Schema/Opc.Ua.NodeSet2.xml --xml=$PATH_UA_NODESET/DI/Opc.Ua.Di.NodeSet2.xml $PATH_SRC_GENERATED/namespace_di_generated

# Compile NS4 Model
#echo "\nNodeset_compiler MODEL NS4  by nodeset_compiler.py\n"
#$PYTHON $PATH_TOOLS/nodeset_compiler/nodeset_compiler.py --types-array=UA_TYPES --types-array=UA_TYPES_DI --existing=$PATH_UA_NODESET/Schema/Opc.Ua.NodeSet2.xml --existing=$PATH_UA_NODESET/DI/Opc.Ua.Di.NodeSet2.xml --xml=$PATH_UA_NODESET/../model/$CS_NODESET/$FILE_XML_MODEL_NS4 $PATH_SRC_GENERATED/$NAME_NAMESPACE_MODEL_NS4


# 
# Build Server
# 
echo "\n\nBuild Server\n"
$SRC_GENERATED/../tools/build_di

