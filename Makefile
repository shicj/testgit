CCompile = gcc
CppCompile = g++
SharedLib = -lpthread
LibDir =
IncDir =
Output = http
CompileOpts = -Wall -g
Macro = 
LinkOpts = 
Objs = entry.o common.o threadpool.o


all:$(Output)


#link
$(Output):$(Objs)
	$(CppCompile) $^ $(LibDir) $(SharedLib) $(LinkOpts) -o $@


#compile	
%.o:%.cpp
	$(CppCompile) -c $^ $(IncDir) $(CompileOpts) -o $@ $(Macro)

	
clean:
	rm $(Output) -f
	rm $(Objs) -f
	