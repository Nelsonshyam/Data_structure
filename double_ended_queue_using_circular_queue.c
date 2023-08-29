#include <stdio.h>

int main()
{
    int queue[100], n, choice, front = -1, rear = -1,element,i;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    queue[n];
    while (1)
    {
        printf("choices\n1.queue at front\n2.dequeue at front\n3.queue at rear\n4.dequeue at rear\n5.Display\n6.Isempty\n7.front element\n8.rear element\n9.Escape\nEnter the choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the element:");
            scanf("%d", &element);

            if (front == -1 && rear == -1)
            {
                front = rear = 0;
                queue[front] = element;
            }
            else if ((front == 0 && rear == n - 1) || (front == rear + 1))
            {
                printf("Queue is filled\n");
            }
            else if (front == 0)
            {
                front = n - 1;
                queue[front] = element;
            }
            else
            {
                front--;
                queue[front] = element;
            }
        }
        else if (choice == 2)
        {
            if(front == -1 && rear == -1){
                printf("The queue is empty\n");
            }
            else if(front==rear){
                front=rear=-1;
            }
            else if(front == n-1){
                front=0;
            }
            else{
                front++;
            }
        }
        else if (choice == 3)
        {
            printf("Enter the element:");
            scanf("%d",&element);
            if(front == -1&& rear == -1){
                front = rear = 0;
                queue[front] = element;
            }
            else if((front==0 && rear==n-1)||(front==rear+1)){
                printf("The queue is filled\n");
            }
            else if(rear == n-1){
                rear=0;
                queue[rear]=element;
            }
            else{
                rear = (rear+1)%n;
                queue[rear]=element;
            }
        }
        else if (choice == 4)
        {
            if(front==-1&&rear==-1){
                printf("The queue is empty\n");
            }
            else if(front==rear){
                front=rear=-1;
            }
            else if(rear==0){
                rear = n-1;
            }
            else{
                rear--;
            }
        }
        else if (choice == 5)
        {
            if ((front == -1) && (rear == -1))
            {
                printf("The queue is empty\n");
            }
            else
            {
                i = front;
                while (i != rear)
                {
                    printf("%d ", queue[i]);
                    i = (i + 1) % n;
                }
                printf("%d", queue[rear]);
                printf("\n");
            }
        }
        else if (choice == 6)
        {
            if((front==-1)&&(rear==-1)){
                printf("The queue is empty\n");
            }
            else{
                printf("The queue has some element\n");
            }
        }
        else if(choice == 7){
            if((front==-1)&&(rear==-1)){
                printf("The queue is empty\n");
            }
            else{
                printf("The front element is %d\n",queue[front]);
            }
        }
        else if(choice == 8){
            if((front==-1)&&(rear==-1)){
                printf("The queue is empty\n");
            }
            else{
                printf("The rear element is %d\n",queue[rear]);
            }
        }
        else if(choice == 9)
        {
            break;
        }
        else
        {
            printf("You were entered the wrong option, please enter the correct option\n");
        }
    }
}