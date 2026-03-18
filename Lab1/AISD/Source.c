#include <Windows.h>
#include <stdio.h>
#include <time.h>
#define MAX_ELEMENTS 100000
#define Test1 10000
#define Test2 20000
#define Test3 40000

struct Collection 
{
	char* name;
	char* description;
};

struct Twolist
{
	struct Collection* data;
	struct Twolist* prev;
	struct Twolist* next;
};

struct List 
{
	int data;
	struct List* next;
};

void ShowList(struct Twolist* peak)
{
	struct Twolist* p = peak;
	printf("Начало стека ");
	int c = getListCount(peak);
	for (int i = 0; i < c; i++)
	{
		printf("%s(%s) ", p->data->name, p->data->description);
		p = p->prev;
	}

	printf("Конец стека");
}

int getListCount(struct Twolist* list)
{
	struct Twolist* p = list;
	int c = 0;
	while (p != NULL)
	{
		p = p->prev;
		c++;
	}
	return c;
}

struct Twolist* push(struct Collection* data,struct Twolist* old) 
{
	struct Twolist* newlist = (struct Twolist*)malloc(sizeof(struct Twolist));
	old->next = newlist;
	newlist->prev = old;
	newlist->data = data;
	newlist->next = NULL;
	return newlist;
}

struct Twolist* pop(struct Twolist* list) 
{
	struct Twolist* p;
	if(list->prev == NULL && list->next != NULL)
	{
		p = list->next;
		p->prev = NULL;
		free(list);
		while (p->next != NULL)
		{
			p = p->next;
		}
		return p;
	}
	else if (list->prev != NULL && list->next == NULL) 
	{
		p = list->prev;
		p->next = NULL;
		free(list);
		return p;
	}
	else if (list->prev != NULL && list->next != NULL) 
	{
		p = list->next;
		p->prev = list->prev;
		list->prev->next = p;
		free(list);
		while (p->next != NULL) 
		{
			p = p->next;
		}
		return p;
	}
	free(list);
	return NULL;
	
}

struct Twolist* popIndex(struct Twolist* peak, int index) 
{
	int c = getListCount(peak);
	if (index > c) 
	{
		return;
	}
	struct Twolist* p = peak;
	for (int i = 0; i < c - index - 1;i++) 
	{
		p = p->prev;
	}
	peak = pop(p);
	return peak;
}

struct Twolist* insertAtTheEnd() 
{

}

struct Collection* peek(struct Twolist* list) 
{
	if (list == NULL) 
	{
		return "Пусто";
	}
	return list->data;
}

char* listOfCollections[9] =
{
	"Dictionary","List","Queue","Stack","LinkedList","ObservableCollection","SortedList","HashSet","SortedSet"
};

void insertSort(int* arr, int arrlength)
{
	
	for (int i = 1;i < arrlength;i++) 
	{
		int save = arr[i];
		int j = i;
		while (save < arr[j - 1]) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = save;
	}
}

void swap(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int low, int high) 
{
	int pivot = arr[low];
	int i = low;
	int j = high;

	while (i < j) 
	{
		while (arr[i] <= pivot && i <= high - 1) 
		{
			i++;
		}
		while (arr[j] > pivot && j >= low + 1) 
		{
			j--;
		}
		if (i < j) 
		{
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[low], &arr[j]);
	return j;
}

void quickSort(int* arr,int low,int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

void swapListElements(struct List* a, struct List* b) 
{
	a->next = b->next;
	b->next = a;
}

struct List* partitionList(struct List* list,struct List* low, struct List* high) 
{
	struct List* pivot = low;
	struct List* ptr = low;
	struct List* newrootlow = NULL;
	struct List* newroothigh = NULL;
	while (ptr != NULL) 
	{
		if (ptr->data < pivot->data) 
		{
			newrootlow->next = ptr;
			newrootlow = newrootlow->next;
		}
		else 
		{
			newroothigh->next = ptr;
			newroothigh = newroothigh->next;
		}
	}
}

void quickSortList(struct List* list) 
{
	if () 
	{

	}
}

void showArray(int* arr,int arrlength) 
{
	for (int i = 0; i < arrlength; i++) 
	{
		printf("%d ", arr[i]);
	}
}

int isSortedList(struct List* start) 
{
	int min = start->data;
	for (struct List* p = start; p != NULL; p = p->next) 
	{
		if (min > p->data) 
		{
			return 0;
		}
		min = p->data;
	}
	return 1;
}

void printList(struct List* root)
{
	struct List* p = root;
	while (p != NULL)
	{
		printf("(%d) -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

struct List* insertSortList(struct List* list) 
{
	struct List* prev, * savenext, * save, * newroot = NULL;
	for (struct List* i = list; i != NULL;) 
	{
		save = i;
		savenext = newroot;
		i = i->next;

		for (prev = NULL; (savenext != NULL) && (savenext->data < save->data);) 
		{
			prev = savenext;
			savenext = savenext->next;
		}

		if (prev == NULL) 
		{
			newroot = save;
			save->next = savenext;
		}
		else 
		{
			prev->next = save;
			save->next = savenext;
		}
	}

	if (newroot != NULL) 
	{
		list = newroot;
	}
}

enum Sort 
{
	InsertSort,
	QuickSort
};

int checkArray(int* arr, int arrlength) 
{
	int min = arr[0];
	for (int i = 1; i < arrlength; i++) 
	{
		if (min > arr[i]) 
		{
			return 0;
		}
	}
	return 1;
}

void reset(int* arr, int arrlength) 
{
	for (int i = 0; i < arrlength; i++) 
	{
		arr[i] = rand() % 100000;
	}
}

struct List* copyList(struct List* listtocopy) 
{
	struct List* p = listtocopy;
	struct List* newroot = (struct List*)malloc(sizeof(struct List));
	struct List* newrootpointer = newroot;
	newroot->data = p->data;
	p = p->next;
	while (p != NULL) 
	{
		newrootpointer->next = (struct List*)malloc(sizeof(struct List));
		newrootpointer = newrootpointer->next;
		newrootpointer->data = p->data;
		p = p->next;
	}
	newrootpointer->next = NULL;
	return newroot;
}

void fillList(struct List* start,int count) 
{
	struct List* p = start;
	p->data = rand() % 100000;
	for (int i = 0; i < count-1; i++) 
	{
		p->next = (struct List*)malloc(sizeof(struct List));
		p = p->next;
		p->data = rand() % 100000;
	}
	p->next = NULL;
}

void resetList(struct List* resettable, struct List* resetlist) 
{
	struct List* p = resetlist;
	struct List* p1 = resettable;
	while (p1 != NULL && p != NULL) 
	{
		p1->data = p->data;
		p1 = p1->next;
		p = p->next;
	}
}

double sortListTest(struct List* start,struct List* resetlist,int count, enum Sort sort) 
{
	double result = 0.0;
	switch (sort) 
	{
	case InsertSort:
		for(int i = 0;i < count;i++)
		{
			clock_t t1 = clock();
			insertSortList(start);
			clock_t t2 = clock();
			resetList(start, resetlist);
			result += (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		break;
	case QuickSort:

		break;
	}

	return (double)(result / count);
}

double sortTest(int* arr, int arrlength, int count, enum Sort sort)
{

	reset(arr, arrlength);

	double result = 0.0;

	switch (sort)
	{
	case InsertSort:
		for (int i = 0; i < count; i++)
		{
			clock_t t1 = clock();
			insertSort(arr, arrlength);
			clock_t t2 = clock();
			result += (double)(t2 - t1) / CLOCKS_PER_SEC;
			reset(arr, arrlength);
		}
		break;
	case QuickSort:
		for (int i = 0; i < count; i++)
		{
			clock_t t1 = clock();
			quickSort(arr, 0, arrlength - 1);
			clock_t t2 = clock();
			result += (double)(t2 - t1) / CLOCKS_PER_SEC;
			reset(arr, arrlength);
		}
		break;
	}


	return result / count;

}

void main() 
{
	SetConsoleCP(1251);//asokidaskid;l
	SetConsoleOutputCP(1251);

	/*clock_t t1 = clock();
	struct Twolist* peak = (struct Twolist*)malloc(sizeof(struct Twolist));
	struct Collection* firstitem = (struct Colleciton*)malloc(sizeof(struct Collection));
	firstitem->name = listOfCollections[0];
	firstitem->description = "Первый предмет";
	peak->data = firstitem;
	peak->prev = NULL;
	peak->next = NULL;
	for (int i = 0; i < 10000000; i++)
	{
		struct Collection* pushable = (struct Collection*)malloc(sizeof(struct Collection));
		pushable->name = listOfCollections[(i % 9)];
		pushable->description = "Потом";
		peak = push(pushable, peak);
	}
	clock_t t2 = clock();

	printf("%d\n", getListCount(peak));

	printf("\nВремя пуша: %f\n", (float)(t2 - t1) / CLOCKS_PER_SEC);
	printf("\n");
	clock_t t3 = clock();
	for (int i = 0; i < 10000001; i++) 
	{
		peak = pop(peak);
	}
	clock_t t4 = clock();
	printf("\nВремя попа: %f\n", (float)(t4 - t3) / CLOCKS_PER_SEC);*/


	/*int arr[Test1];
	printf("Сортировка Вставками c %d элементами - %f\n",Test1, sortTest(arr, Test1, 100, QuickSort));
	int arr1[Test2];
	printf("Сортировка Вставками c %d элементами - %f\n", Test2, sortTest(arr1, Test2, 100, QuickSort));
	int arr2[Test3];
	printf("Сортировка Вставками c %d элементами - %f\n", Test3, sortTest(arr2, Test3, 100, QuickSort));*/

	struct List* root = (struct List*)malloc(sizeof(struct List));
	fillList(root, Test1);
	struct List* reserve = copyList(root);
	printf("%f - среднее время сортировки Вставками\n", sortListTest(root, reserve, 10, InsertSort));
}