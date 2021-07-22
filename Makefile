tree.js:
	emcc tree.c -Os -s ASSERTIONS=1 -s EXPORTED_FUNCTIONS='["_malloc", "_createTree", "_inOrderTraversal", "_insert", "_maximum", "_minimum", "_search"]' EXPORTED_RUNTIME_METHODS='["ccall"]' -s MODULARIZE=1
