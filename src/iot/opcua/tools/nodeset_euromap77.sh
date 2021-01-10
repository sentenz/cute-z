#!/bin/sh

# Fixed paths
PYTHON="/usr/bin/python"

PATH_OPEN62541="/home/pi/open62541/open62541"
PATH_UA_NODESET="$PATH_OPEN62541/examples/sentenz/sc/model/ua-nodeset"
PATH_TOOLS="$PATH_OPEN62541/tools"
SRC_GENERATED="/$PATH_OPEN62541/examples/sentenz/sc/model/generate"

# Need to be changed
CS_NODESET="EUROMAP77"
PATH_SRC_GENERATED="$SRC_GENERATED/$CS_NODESET"

# Note NS0 (UA) and NS1 (DI) are currently created by open62541 wirh the amalgation flag
#
# CS EUROMAP 83
CS_TYPE_NS2="UA_TYPES_EUROMAP83"

FILE_CSV_CS_NS2="Opc_Ua.EUROMAP83.RC1_01.NodeId.csv"
FILE_XML_CS_NS2="Opc_Ua.EUROMAP83.1_01.NodeSet2.xml"
FILE_BSD_CS_NS2="Opc_Ua.EUROMAP83.1_01.Types.bsd"

NAME_NODEID_CS_NS2="euromap83_nodeids EUROMAP83"
NAME_TYPES_CS_NS2="types_euromap83"
NAME_NAMESPACE_CS_NS2="namespace_euromap83_generated"

# CS EUROMAP 77
CS_TYPE_NS3="UA_TYPES_EUROMAP77"

FILE_CSV_CS_NS3="Opc_Ua.EUROMAP77.1_00.NodeId.csv"
FILE_XML_CS_NS3="Opc_Ua.EUROMAP77.1_00.NodeSet2.xml"
FILE_BSD_CS_NS3="Opc_Ua.EUROMAP77.1_00.Types.bsd"

NAME_NODEID_CS_NS3="euromap77_nodeids EUROMAP77"
NAME_TYPES_CS_NS3="types_euromap77"
NAME_NAMESPACE_CS_NS3="namespace_euromap77_generated"

# Model_Euromap
FILE_XML_MODEL_NS4="Opc_Ua.EUROMAP77_Model.xml"

NAME_NODEID_MODEL_NS4="model_nodeids MODEL"
NAME_NAMESPACE_MODEL_NS4="namespace_euromap_model_generated"

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

# CS NodeID 83
echo "Generate nodeid header $CS_NODESET 83 NodeID by generate_nodeid_header.py\n"
$PYTHON $PATH_TOOLS/generate_nodeid_header.py $PATH_UA_NODESET/$CS_NODESET/Euromap83/$FILE_CSV_CS_NS2 $PATH_SRC_GENERATED/$NAME_NODEID_CS_NS2

# CS NodeID 82
echo "Generate nodeid header $CS_NODESET 77 NodeID by generate_nodeid_header.py\n"
$PYTHON $PATH_TOOLS/generate_nodeid_header.py $PATH_UA_NODESET/$CS_NODESET/Euromap77/$FILE_CSV_CS_NS3 $PATH_SRC_GENERATED/$NAME_NODEID_CS_NS3

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

# Generate Datatype NS2
echo "Generate datatypes $CS_NODESET 83 NS2 by generate_datatypes.py\n"
$PYTHON $PATH_TOOLS/generate_datatypes.py --namespace=3 --type-bsd=$PATH_UA_NODESET/$CS_NODESET/Euromap83/$FILE_BSD_CS_NS2 --type-csv=$PATH_UA_NODESET/$CS_NODESET/Euromap83/$FILE_CSV_CS_NS2 --no-builtin $PATH_SRC_GENERATED/$NAME_TYPES_CS_NS2

# Generate Datatype NS3
echo "Generate datatypes $CS_NODESET 77 NS3 by generate_datatypes.py\n"
$PYTHON $PATH_TOOLS/generate_datatypes.py --namespace=4 --type-bsd=$PATH_UA_NODESET/$CS_NODESET/Euromap77/$FILE_BSD_CS_NS3 --type-csv=$PATH_UA_NODESET/$CS_NODESET/Euromap77/$FILE_CSV_CS_NS3 --no-builtin $PATH_SRC_GENERATED/$NAME_TYPES_CS_NS3

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

# Compile NS2 CS
echo "\nNodeset_compiler CS NS2 83 by nodeset_compiler.py\n"
$PYTHON $PATH_TOOLS/nodeset_compiler/nodeset_compiler.py --internal-headers --types-array=UA_TYPES --types-array=UA_TYPES_DI --types-array=$CS_TYPE_NS2 --existing=$PATH_UA_NODESET/Schema/Opc.Ua.NodeSet2.xml --existing=$PATH_UA_NODESET/DI/Opc.Ua.Di.NodeSet2.xml --xml=$PATH_UA_NODESET/$CS_NODESET/Euromap83/$FILE_XML_CS_NS2  $PATH_SRC_GENERATED/$NAME_NAMESPACE_CS_NS2

# Compile NS3 CS
echo "\nNodeset_compiler CS NS3 82 by nodeset_compiler.py\n"
$PYTHON $PATH_TOOLS/nodeset_compiler/nodeset_compiler.py --internal-headers --types-array=UA_TYPES --types-array=UA_TYPES_DI --types-array=$CS_TYPE_NS2 --types-array=$CS_TYPE_NS3 --existing=$PATH_UA_NODESET/Schema/Opc.Ua.NodeSet2.xml --existing=$PATH_UA_NODESET/DI/Opc.Ua.Di.NodeSet2.xml --existing=$PATH_UA_NODESET/$CS_NODESET/Euromap83/$FILE_XML_CS_NS2 --xml=$PATH_UA_NODESET/$CS_NODESET/Euromap77/$FILE_XML_CS_NS3  $PATH_SRC_GENERATED/$NAME_NAMESPACE_CS_NS3

# Compile NS4 Model
echo "\nNodeset_compiler MODEL NS4  by nodeset_compiler.py\n"
$PYTHON $PATH_TOOLS/nodeset_compiler/nodeset_compiler.py --types-array=UA_TYPES --types-array=UA_TYPES_DI --types-array=$CS_TYPE_NS2 --types-array=$CS_TYPE_NS3 --existing=$PATH_UA_NODESET/Schema/Opc.Ua.NodeSet2.xml --existing=$PATH_UA_NODESET/DI/Opc.Ua.Di.NodeSet2.xml --existing=$PATH_UA_NODESET/$CS_NODESET/Euromap83/$FILE_XML_CS_NS2 --existing=$PATH_UA_NODESET/$CS_NODESET/Euromap77/$FILE_XML_CS_NS3  --xml=$PATH_UA_NODESET/../model/$CS_NODESET/$FILE_XML_MODEL_NS4 $PATH_SRC_GENERATED/$NAME_NAMESPACE_MODEL_NS4


# 
# Build Server
# 
echo "\n\nBuild Server\n"
$SRC_GENERATED/../tools/build_euromap77

