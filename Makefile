tree.js:
	emcc ASSERTIONS=1 tree.c -Os -o tree.js -s EXPORTED_FUNCTIONS='["_malloc", "_createTree", "_inOrderTraversal", "_postOrderTraversal", "_preOrderTraversal", "_insert", "_maximum", "_minimum", "_search"]' EXPORTED_RUNTIME_METHODS='["ccall"]' -s MODULARIZE=1
