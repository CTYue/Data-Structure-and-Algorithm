//	//尾插法
//	term *new_term = new term(c,p);
//	term *ptr = head;
//	if(head == nullptr)
//	{
//		head = new_term;
//		ptr = head;
//	}
//
//	else
//	{
////			head->next = new_term;
////			head = head->next;//由于head最终指向head->next,所以仅有head有值，而head->next不存在
//			ptr->next = new_term;
//			ptr = ptr->next;
//	}
//	while( ptr != nullptr )
//	{
//		head = ptr;//把最后一组值给了head
////		head = head->next;
//		ptr = ptr->next;
//		cout << "Hello World!" << endl;
//	}
