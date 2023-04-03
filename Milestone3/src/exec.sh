make
cd ..
./milestone3 -i tests/test_1.java
./MyASTgenerator -i tests/test_1.java -o yo.dot
dot -Tpng yo.dot >yo.png
