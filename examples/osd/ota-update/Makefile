# Set this to the name of your sketch (without extension .pde)
SKETCH=sketch
EXE=ota

all: $(EXE)

CONTIKI=../../..

# Contiki IPv6 configuration
CONTIKI_WITH_IPV6 = 1

CFLAGS += -DPROJECT_CONF_H=\"project-conf.h\"

PROJECT_SOURCEFILES += ${SKETCH}.cpp

# automatically build RESTful resources
REST_RESOURCES_DIR = ./resources
REST_RESOURCES_DIR_COMMON = ../resources-common
REST_RESOURCES_FILES= $(notdir \
    $(shell find $(REST_RESOURCES_DIR) -name '*.c') \
    $(shell find $(REST_RESOURCES_DIR_COMMON) -name '*.c') \
    )

PROJECTDIRS += $(REST_RESOURCES_DIR) $(REST_RESOURCES_DIR_COMMON)
PROJECT_SOURCEFILES += $(REST_RESOURCES_FILES)

# variable for Makefile.include
ifneq ($(TARGET), minimal-net)
CFLAGS += -DUIP_CONF_IPV6_RPL=1
else
# minimal-net does not support RPL under Linux and is mostly used to test CoAP only
${info INFO: compiling without RPL}
CFLAGS += -DUIP_CONF_IPV6_RPL=0
CFLAGS += -DHARD_CODED_ADDRESS=\"fdfd::10\"
${info INFO: compiling with large buffers}
CFLAGS += -DUIP_CONF_BUFFER_SIZE=2048
CFLAGS += -DREST_MAX_CHUNK_SIZE=1024
CFLAGS += -DCOAP_MAX_HEADER_SIZE=640
endif

# linker optimizations
SMALL=1

# REST Engine shall use Erbium CoAP implementation
APPS += er-coap
APPS += rest-engine
APPS += arduino json-resource json ota-update

include $(CONTIKI)/Makefile.include
include $(CONTIKI)/apps/arduino/Makefile.include

AVRDUDE_PORT=/dev/ttyUSB0
