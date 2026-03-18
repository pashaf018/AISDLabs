//void swap(struct Twolist* p1, struct  Twolist* p2)
//{
//	struct Twolist* temp = p1;
//	if (p1->next = p2)
//	{
//		p1->prev = p2;
//		p1->next = p2->next;
//		p1->data = p2->data;
//		p2->prev = temp->prev;
//		p2->next = temp;
//		p2->data = temp->data;
//	}
//	else if (p1->prev = p2)
//	{
//		p1->prev = p2->prev;
//		p1->next = p2;
//		p1->data = p2->data;
//		p2->prev = temp;
//		p2->next = temp->next;
//		p2->data = temp->data;
//	}
//	else
//	{
//		p1->prev = p2->prev;
//		p1->next = p2->next;
//		p1->data = p2->data;
//		p2->prev = temp->prev;
//		p2->next = temp->next;
//		p2->data = temp->data;
//	}
//}
//
//void insertSortingDecrease(struct Twolist* peak)
//{
//	struct Twolist* lastinserted = peak;
//	int M = getListCount(peak);
//	for (int i = 1; i < M; i++)
//	{
//		struct Twolist* p = lastinserted->prev;
//		struct Collection* save = p->data;
//		int j = i;
//		while (j-- > 0 && (strcmp(p->next->data->name, save->name) < 0))
//		{
//			p->data = p->next->data;
//			p = p->next;
//		}
//		p->data = save;
//		lastinserted = lastinserted->prev;
//	}
//}
//
//void insertSortingIncrease(struct Twolist* peak)
//{
//	struct Twolist* lastinserted = peak;
//	int M = getListCount(peak);
//	for (int i = 1; i < M; i++)
//	{
//		struct Twolist* p = lastinserted->prev;
//		struct Collection* save = p->data;
//		int j = i;
//		while (j-- > 0 && (strcmp(p->next->data->name, save->name) > 0))
//		{
//			p->data = p->next->data;
//			p = p->next;
//		}
//		p->data = save;
//		lastinserted = lastinserted->prev;
//	}
//}