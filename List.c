#include "List.h"

/*
====================
ListFree

	Очищает память от всех эллементов
====================
*/
int ListFree( usList_t ** list ) {
	while ( *list != NULL ) {
		usList_t * tempPoint = *list;
		*list = (*list)->rightNode_;
		free( tempPoint->data_ );
		free( tempPoint );
	}
	return 0;
}

/*
====================
ListPushBack

	Добавляет элемент в конец списка
====================
*/
int	ListPushBack( usList_t ** list, void *data ) {
	if ( (*list) == NULL ) {
		(*list) = malloc( sizeof( usList_t ) );
		(*list)->leftNode_ = NULL;
		(*list)->rightNode_ = NULL;
		(*list)->data_ = data;
	} else {
		usList_t * tempPoint = *list;
		while ( tempPoint->rightNode_ != NULL ) {
			tempPoint = tempPoint->rightNode_;
		}
		tempPoint->rightNode_ = malloc( sizeof( usList_t ) );
		tempPoint->rightNode_->leftNode_ = tempPoint;
		tempPoint->rightNode_->rightNode_ = NULL;
		tempPoint->rightNode_->data_ = data;
	}
	return 0;
}

/*
====================
ListPushFront

	Добавляет элемент в начало списка
====================
*/
int	ListPushFront( usList_t ** list, void *data ) {
	if ( (*list)->data_ == NULL ) {
		(*list) = malloc( sizeof( usList_t ) );
		(*list)->leftNode_ = NULL;
		(*list)->rightNode_ = NULL;
		(*list)->data_ = data;
	} else {
		(*list)->leftNode_ = malloc( sizeof( usList_t ) );
		(*list)->leftNode_->leftNode_ = NULL;
		(*list)->leftNode_->rightNode_ = (*list);
		(*list)->leftNode_->data_ = data;
		(*list) = (*list)->leftNode_;
	}
	return 0;
}

/*
====================
ListSize

	Возвращает размер списка
====================
*/
int	ListSize( usList_t ** list ) {
	int i = 0;
	usList_t * pList = *list;
	while ( pList != NULL ) {
		pList = pList->rightNode_;
		i++;
	}
	return i;
}

/*
====================
ListGetElement

	Возвращает элемент под номером numElement, в случае ошибки возвращает NULL
====================
*/
void * ListGetElement( usList_t ** list, int numElement ) {
	if ( numElement < 0 || *list == NULL || numElement >= ListSize( list ) ) {
		return NULL;
	}
	usList_t * pList = *list;
	for ( int i = 0; i < numElement; i++ ) {
		pList = pList->rightNode_;
	}
	return pList->data_;
}

/*
====================
ListDeleteElementAtNumber

	Удаляет элемент под номером numElement, в случае ошибки возвращает -1
====================
*/
int ListDeleteElementAtNumber( usList_t ** list, int numElement ) {
	if ( numElement < 0 || *list == NULL || numElement >= ListSize( list ) ) {
		return -1;
	}
	usList_t * pList = (*list);
	for ( int i = 0; i < numElement; i++ ) {
		pList = pList->rightNode_;
	}
	if ( pList->leftNode_ == NULL && pList->rightNode_ == NULL ) {
		free( (*list)->data_ );
		free( (*list) );
		(*list) = NULL;
	} else if ( pList->leftNode_ == NULL ) {
		(*list) = (*list)->rightNode_;
		free( (*list)->leftNode_->data_ );
		free( (*list)->leftNode_ );
		(*list)->leftNode_ = NULL;
	} else if ( (*list)->rightNode_ == NULL ) {
		pList->leftNode_->rightNode_ = NULL;
		free( pList->data_ );
		free( pList );
	} else {
		pList->leftNode_->rightNode_ = pList->rightNode_;
		pList->rightNode_->leftNode_ = pList->leftNode_;
		free( pList->data_ );
		free( pList );
	}
	return 0;
}

/*
====================
ListDeleteElementAtData

	Удаляет элемент у которого совпадает указатель данных, в случае ошибки возвращает -1
====================
*/
int ListDeleteElementAtData( usList_t ** list, void * data ) {
	if ( data == NULL || *list == NULL ) {
		return -1;
	}
	usList_t * pList = (*list);
	while ( pList->data_ != data ) {
		pList = pList->rightNode_;
		if ( pList == NULL ) {
			return -1;
		}
	}
	if ( pList->leftNode_ == NULL && pList->rightNode_ == NULL ) {
		free( (*list)->data_ );
		free( (*list) );
		(*list) = NULL;
	} else if ( pList->leftNode_ == NULL ) {
		(*list) = (*list)->rightNode_;
		free( (*list)->leftNode_->data_ );
		free( (*list)->leftNode_ );
		(*list)->leftNode_ = NULL;
	} else if ( (*list)->rightNode_ == NULL ) {
		pList->leftNode_->rightNode_ = NULL;
		free( pList->data_ );
		free( pList );
	} else {
		pList->leftNode_->rightNode_ = pList->rightNode_;
		pList->rightNode_->leftNode_ = pList->leftNode_;
		free( pList->data_ );
		free( pList );
	}
	return 0;
}

/*
====================
ListPopBack

	Возвращает последний эллемент списка, в случае ошибки возвращает NULL
====================
*/
void * ListPopBack( usList_t ** list ) {
	if ( *list == NULL ) {
		return NULL;
	}
	usList_t * pList = *list;
	void * data = NULL;
	while ( pList->rightNode_ != NULL ) {
		pList = pList->rightNode_;
	}
	if ( pList->leftNode_ == NULL ) {
		data = (*list)->data_;
		free( *list );
		*list = NULL;
	} else {
		data = pList->data_;
		pList->leftNode_->rightNode_ = NULL;
		free( pList );
	}
	return data;
}

/*
====================
ListPopFront

	Возвращает первый эллемент списка, в случае ошибки возвращает NULL
====================
*/
void * ListPopFront( usList_t ** list ) {
	if ( *list == NULL ) {
		return NULL;
	}
	void * data;
	if ( (*list)->rightNode_ == NULL ) {
		data = (*list)->data_;
		free( *list );
		*list = NULL;
	} else {
		data = (*list)->data_;
		(*list) = (*list)->rightNode_;
		free( (*list)->leftNode_ );
		(*list)->leftNode_ = NULL;
	}
	return data;
}
