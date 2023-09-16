#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct ShoppingItem
{
	char name[50]; // 商品名称
	int quantity; // 商品数量
 	struct ShoppingItem* next; // 指向下一个节点的指针
};
//然后，我们创建一个链表头指针，表示购物清单的起始点：
struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
struct ShoppingItem* p=NULL;
//1. 添加商品到购物清单：
void addItem(char itemName[], int itemQuantity)
{
 	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 	//此处填写若干语句；
 	strcpy(newItem->name,itemName);
 	newItem->quantity=itemQuantity;
 	newItem->next==NULL;
 	if(shoppingList==NULL)
 	{
 		shoppingList=newItem;
	 }
	 else
	 {
	 	p->next=newItem;
	 }
	 p=newItem;
}
//2. 从购物清单中移除商品：
void removeItem(char itemName[])
{
	struct ShoppingItem* current = shoppingList;
 	struct ShoppingItem* previous = NULL;
 	while (current != NULL)
	{
 		if (strcmp(current->name, itemName) == 0)
		 {
 			if (previous != NULL)
			{
 				previous->next = current->next;
			}
			else
			{
				shoppingList = current->next;
			}
			free(current);
			break;
		}
		//此处填写两行；
		previous=current;
		current=current->next;
	}
}
//3. 查看购物清单：
void displayList()
{
	struct ShoppingItem* current = shoppingList;
	printf("购物清单:\n");
	while (current != NULL)
	{
		printf("%s - 数量：%d\n", current->name, current->quantity);
		//此处填写一句；
		current=current->next;
	}
}
//4. 修改购物清单中商品的数量：
void updateQuantity(char itemName[], int newItemQuantity)
{
	struct ShoppingItem* current = shoppingList;
	while (current != NULL)
	{
		if (strcmp(current->name, itemName) == 0)
		{
			//此处填写一句。
			current->quantity = newItemQuantity;
			break;
		}
	current = current->next;
	}
}
//5. 清空购物清单：
void clearList()
{
	while (shoppingList != NULL)
	{
		//此处填写两句。
		struct ShoppingItem* temp = shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}
//6. 计算购物清单中商品的总数量：
int totalQuantity()
{
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL)
	{
		//此处填写两句；
		total+=current->quantity;
		current = current->next;
	}
	return total;
}
//7. 查找购物清单中的商品：
void findItem(char itemName[])
{
	struct ShoppingItem* current = shoppingList;
	printf("查找商品 \"%s\" ：\n", itemName);
	while (current != NULL)
	{
		if (strcmp(current->name, itemName) == 0)
		{
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		//此处填写一句。
		current = current->next;
	}
	printf("未找到商品 \"%s\"。\n", itemName);
}
//8. 排序购物清单：
void sortList()
{
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL)
	{
		nextItem = current->next;
		while (nextItem != NULL) 
		{
			if (strcmp(current->name, nextItem->name) > 0)
			{
				// 交换商品信息
				//此处填写 3 句；
				strcpy(tempName,current->name);
				strcpy(current->name,nextItem->name);
				strcpy(nextItem->name,tempName);
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
 		}
		current = current->next;
	}
}
//9. 合并购物清单：
//假设你有两个不同的购物清单，你希望将它们合并成一个。
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2)
{
	struct ShoppingItem* current = *list1;
	// 遍历到第一个购物清单的末尾
	//补充循环语句；
	while(current->next!=NULL)
		current = current->next; 
	// 将第二个购物清单连接到第一个清单的末尾
	current->next = *list2;
	*list2 = NULL; // 清空第二个购物清单的头指针，防止误用
}
//10. 删除购物清单中的商品：
//实现一个函数，可以根据商品名称删除购物清单中的商品项。如果有多个相同名称的商品，
//可以选择删除其中一个或全部。
void deleteItem(char itemName[], int deleteAll)
{
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL)
	{
		if (strcmp(current->name, itemName) == 0)
		{
			if (prev == NULL)
			{
				// 如果要删除的是第一个节点
				struct ShoppingItem* temp = shoppingList;
				//填写一句；
				
				shoppingList = shoppingList->next;
				free(temp);
			if (!deleteAll)
				break;
			}
			else
			{
				// 如果要删除的不是第一个节点
				//填写一句；
				prev->next=current->next;
				free(current);
				current = prev->next;
				if (!deleteAll) break;
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	if(current==NULL) p=prev;
}
struct ShoppingItem* creatList()
{
	struct ShoppingItem *p,*q,*h;
	
	q=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	h=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	h=NULL;
	
	do
	{
		p=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
		scanf("%s %d",p->name,&p->quantity);
		p->next=NULL;
		if(h==NULL&&p->quantity!=0)
			h=p;
		else
			q->next=p;
		q=p;
		
	}while(p->quantity!=0);
	
	return h;
	}	
int main()
{
	char itemname[50];
	char name[50];
	int itemquantity,newItemQuantity,total,deleteAll;
	int x;
	printf("输入数字开始相应功能：\n");
	printf("1. 添加商品到购物清单.\n");
	printf("2. 从购物清单中移除商品.\n");
	printf("3. 查看购物清单.\n");
	printf("4. 修改购物清单中商品的数量.\n");
	printf("5. 清空购物清单.\n");
	printf("6. 计算购物清单中商品的总数量.\n");
	printf("7. 查找购物清单中的商品.\n");
	printf("8. 排序购物清单.\n");
	printf("9. 合并购物清单.\n");
	printf("10. 删除购物清单中的商品.\n");
	scanf("%d",&x);
	while(x!=0)
	{
		if(x==1)
		{
			scanf("%s%d",itemname,&itemquantity);
			addItem(itemname, itemquantity);
		}
		if(x==2)
		{
			scanf("%s",name);
			removeItem(name);
		}
		if(x==3)
		{
			displayList();
			printf("1\n");
		}
		if(x==4)
		{
			scanf("%s %d",name,&newItemQuantity);
			updateQuantity(name, newItemQuantity);
		}
		if(x==5)
		{
			clearList();
		}
		if(x==6)
		{
			total = totalQuantity();
			printf("%d",total);
		}
		if(x==7)
		{
			scanf("%s",name);
			findItem(name);
		}
		if(x==8)
		{
			sortList();
		}
		if(x==9)
		{	printf("请输入第一个购物清单，按0退出\n");
			struct ShoppingItem*h1;
			h1=creatList();
			struct ShoppingItem**l1;
			l1=&h1;
			printf("请输入第二个购物清单，按0退出\n");
			struct ShoppingItem*h2;
			struct ShoppingItem**l2;
			h2=creatList();
			l2=&h2;
			if(*l1!=NULL) mergeLists(l1,l2);
			shoppingList=*l1;
		}
		if(x==10)
		{
			scanf("%s %d",name,&deleteAll);
			deleteItem(name,deleteAll);
		}
		scanf("%d",&x);
	}
	return 0;
}
