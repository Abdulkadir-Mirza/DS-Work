#include <stdio.h>

struct Rectangle
{
	int length;
	int breadth;
};

void Initialize(struct Rectangle *r,int l,int b)
{
	r->length=l;
	r->breadth=b;
}

int Area(struct Rectangle r)
{
	return r.length*r.breadth;
}

void ChangeLength(struct Rectangle *r,int l)
{
	r->length=l;
}

int main()
{
	struct Rectangle r;
	Initialize(&r,10,5);
	Area(r);
	printf("%d\n",Area(r));
	ChangeLength(&r,20);
	printf("%d\n",Area(r));

}
