#include "aeten/lang/ArrayList.h"

aeten_lang__List * aeten_lang__ArrayList__new(size_t element_size, size_t length) {
	aeten_lang__ArrayList *list = (aeten_lang__ArrayList *) calloc(1, sizeof(aeten_lang__ArrayList));
	return cast_ref(aeten_lang__List, aeten_lang__ArrayList__initialize(list, element_size, length));
}

aeten_lang__ArrayList * aeten_lang__ArrayList__initialize(aeten_lang__ArrayList *list, size_t element_size, size_t length) {
	aeten_lang__object__init(aeten_lang__ArrayList, list);
	aeten_lang__List__init(aeten_lang__ArrayList, list);
	list->_private.elements = calloc(length, element_size);
	list->_private.length = length;
	list->_private.element_size = element_size;
	return list;
}

void aeten_lang__ArrayList__finalize(aeten_lang__List *list) {
	free(cast_ref(aeten_lang__ArrayList, list)->_private.elements);
}

void aeten_lang__ArrayList__set(aeten_lang__List *list, unsigned int position, void *element) {
	aeten_lang__ArrayList *array_list = cast_ref(aeten_lang__ArrayList, list);
	if(position >= array_list->_private.length) {
		// TODO: throw exception
	}
	unsigned long pointer = (unsigned long)array_list->_private.elements;
	pointer += position*array_list->_private.element_size;
	memcpy((void*)pointer, element, array_list->_private.element_size);
}

void * aeten_lang__ArrayList__get(aeten_lang__List *list, unsigned int position) {
	aeten_lang__ArrayList *array_list = cast_ref(aeten_lang__ArrayList, list);
	if(position >= array_list->_private.length) {
		// TODO: throw exception
	}
	unsigned long pointer = (unsigned long)array_list->_private.elements;
	pointer += position*array_list->_private.element_size;
	return (void*)pointer;
}

void aeten_lang__ArrayList__add(aeten_lang__List *list, void *element) {
	// TODO: throw unsupported exception
}

size_t aeten_lang__ArrayList__size(aeten_lang__List *list) {
	return cast_ref(aeten_lang__ArrayList, list)->_private.length;
}
