#include "aeten/lang/Iterator.h"

#include "aeten/lang/start-interface.h"
#define AETEN_LANG_ITERATOR \
	aeten_lang__interface(aeten_lang__Iterable)

#define AETEN_LANG_METHODS \
	aeten_lang__method(aeten_lang__Iterator, iterator);

#ifndef _AETEN_LANG_ITERATOR_H
#define _AETEN_LANG_ITERATOR_H
#include "aeten/lang/end-interface.h"

#endif
