SOURCEDIR := src/
INCLUDEDIR := include/
BUILDDIR := bin/
DEPENDENCYDIR := vendor/
SOURCE := $(wildcard $(SOURCEDIR)*.cpp)
INCLUDE := $(wildcard $(INCLUDEDIR)*.h)
#INCLUDE := $(addprefix $(INCLUDEDIR),$(patsubst %.cpp,%.h,$(wildcard *.cpp)))
OBJECTS := $(patsubst $(SOURCEDIR)%, $(BUILDDIR)%, $(patsubst %.cpp,%.o,$(SOURCE)))
HW_LIBS := $(BUILDDIR)HamsterWheel.a

GLEW_CFLAGS := $(shell pkg-config --cflags --libs glew)
GLFW_CFLAGS := $(shell pkg-config --cflags --libs glfw3)
STB_IMAGE_CFLAGS := -I ./$(DEPENDENCYDIR)dep_stb_image/

CFLAGS := $(GLEW_CFLAGS) $(GLFW_CFLAGS) $(STB_IMAGE_CFLAGS) -I ./$(INCLUDEDIR)

all : $(HW_LIBS)

$(HW_LIBS): $(OBJECTS)
	ar rvs $(BUILDDIR)HamsterWheel.a $(OBJECTS)
$(OBJECTS) : $(INCLUDE) $(SOURCE)
	#$(MAKE) -C $(DEPENDENCYDIR) # run dependency makefile first
	g++ -I $(CFLAGS) -c $(SOURCE)
	mv *.o $(BUILDDIR)

.PHONY : clean
clean :
	rm bin/*

.PHONY : test

test :
	# SOURCE DIR:
	echo $(SOURCEDIR)
	
	# INCLUDE DIR:
	echo $(INCLUDEDIR)
	
	# BUILD DIR:
	echo $(BUILDDIR)
	
	# DEPENDENCY DIR:
	echo $(DEPENDENCYDIR)
	
	# SOURCE FILES:
	echo $(SOURCE)
	
	# HEADER FILES:
	echo $(INCLUDE)
	
	# OBJECT FILES:
	echo $(OBJECTS)

	# CFLAGS
	echo $(GLEW_CFLAGS)
	echo $(GLFW_CFLAGS)
	echo $(STB_IMAGE_CFLAGS)
	echo $(CFLAGS)
