# convenience script 
SOURCE_FILE="main"
EXECUTABLE_FILE="qtdemos"

if [ "$1" = "test" ]; then
    cd /home/geixcowo/db/QTDemos && qmake && make && rm .qmake.stash && rm $SOURCE_FILE.o && ./$EXECUTABLE_FILE
elif [ "$1" = "build" ] || [ "$1" = "" ]; then
    cd /home/geixcowo/db/QTDemos && qmake && make && rm .qmake.stash && rm $SOURCE_FILE.o
fi

