#include "SVGParser.h"
#include "head.h"



void setListToEmpty(List *list);

int main(int argc, char **argv)
{
	int a = 0;
	bool result = false;
	bool result2 = false;
	SVGimage *storage;
	printf("hello\n");
	char *json = NULL;

	char *name = "fill";
	char *value = "6apples";

	
	Attribute *newAttribute = NULL;
	
	newAttribute = malloc(sizeof(Attribute));
	//newAttribute->name = NULL;
	newAttribute->name = malloc(sizeof(char) * strlen(name) + 1);
	strcpy(newAttribute->name, name);
	//newAttribute->value = NULL;	
	newAttribute->value = malloc(sizeof(char) * strlen(value) + 1);
	strcpy(newAttribute->value, value);

	/*
	Circle *circle = malloc(sizeof(Circle));
	circle->cx = 1.0;
	circle->cy = 69.69;
	circle->r = 420.69;
	strcpy(circle->units, "cm");
	circle->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
	//circle->otherAttributes = NULL;
	insertBack(circle->otherAttributes, newAttribute);
	*/

	/*
	Rectangle *rect = malloc(sizeof(Rectangle));
	rect->x = 1.0;
	rect->y = 69.69;
	rect->width = 420.69;
	rect->height = 69.42;
	strcpy(rect->units, "cm");
	rect->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
	insertBack(rect->otherAttributes, newAttribute);

	Path *path = malloc(sizeof(Path));
	path->data = malloc(sizeof(char) * 4 + 1);
	strcpy(path->data, "data");
	path->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
	insertBack(path->otherAttributes, newAttribute);

	Group *group2 = malloc(sizeof(Group));

	group2->rectangles = initializeList(rectangleToString, deleteRectangle, compareRectangles);
	group2->circles = initializeList(circleToString, deleteCircle, compareCircles);
	group2->paths = initializeList(pathToString, deletePath, comparePaths);
	group2->groups = initializeList(groupToString, deleteGroup, compareGroups);
	group2->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

	Group *group = malloc(sizeof(Group));

	group->rectangles = initializeList(rectangleToString, deleteRectangle, compareRectangles);
	group->circles = initializeList(circleToString, deleteCircle, compareCircles);
	group->paths = initializeList(pathToString, deletePath, comparePaths);
	group->groups = initializeList(groupToString, deleteGroup, compareGroups);
	group->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

	insertBack(group->rectangles, rect);
	insertBack(group->circles, circle);
	insertBack(group->paths, path);
	insertBack(group->groups, group2);
	insertBack(group->otherAttributes, newAttribute);

	json = attrToJSON(newAttribute);
	printf("attrToJSON: %s\n", json);
	free(json);

	json = circleToJSON(circle);
	printf("circleToJSON: %s\n", json);
	free(json);

	json = rectToJSON(rect);
	printf("rectToJSON: %s\n", json);
	free(json);

	json = pathToJSON(path);
	printf("pathToJSON: %s\n", json);
	free(json);

	json = groupToJSON(group);
	printf("groupToJSON: %s\n", json);
	free(json);

	List *r = initializeList(rectangleToString, deleteRectangle, compareRectangles);
	List *c = initializeList(circleToString, deleteCircle, compareCircles);
	List *p = initializeList(pathToString, deletePath, comparePaths);
	List *g = initializeList(groupToString, deleteGroup, compareGroups);
	List *oa = initializeList(attributeToString, deleteAttribute, compareAttributes);

	insertBack(r, rect);
	insertBack(c, circle);
	insertBack(p, path);
	insertBack(g, group);
	insertBack(oa, newAttribute);

	insertBack(r, rect);
	insertBack(c, circle);
	insertBack(p, path);
	insertBack(g, group);
	insertBack(oa, newAttribute);

	json = attrListToJSON(oa);
	printf("attrListToJSON: %s\n", json);
	free(json);

	json = circListToJSON(c);
	printf("circListToJSON: %s\n", json);
	free(json);

	json = rectListToJSON(r);
	printf("rectListToJSON: %s\n", json);
	free(json);

	json = pathListToJSON(p);
	printf("pathListToJSON: %s\n", json);
	free(json);

	json = groupListToJSON(g);
	printf("groupListToJSON: %s\n", json);
	free(json);
	*/

	//storage = createSVGimage(argv[1]);

	storage = createValidSVGimage(argv[1], argv[2]);
	//insertBack(storage->circles, circle);

	/*
	json = SVGtoJSON(storage);
	printf("SVGtoJSON: %s\n", json);
	free(json);
	*/

	/*
	if (storage == NULL)
	{
		printf("storage is NULL\n");
	}
	*/

	/*
    result = writeSVGimage(storage, "file2.svg");
    if(result == 1)
    {
        printf("result: true/valid\n");
    }
    else
    {
        printf("result: false/not valid\n");
    }
    */

	/*
	result2 = validateSVGimage(storage, argv[2]);
	if (result2 == true)
	{
		printf("result2: true/valid\n");
	}
	else
	{
		printf("result2: false/not valid\n");
	}
	*/

	//char *print = NULL;
	//print = SVGimageToString(storage);
	//printf("%s", print);
	//free(print);

	/*
	List *list = getGroups(storage);
	printf("group list num: %d\n", getLength(list));
	setListToEmpty(list);
	printf("group list num after emptying: %d\n", getLength(list));
	freeList(list);
	//free(list);
	*/

	setAttribute(storage, RECT, 1, newAttribute);

	result2 = validateSVGimage(storage, argv[2]);

	if (result2 == true)
	{
		printf("result2: true/valid\n");
	}
	else
	{
		printf("result2: false/not valid\n");
	}
	//free(newAttribute->name);
	//free(newAttribute->value);
	//free(newAttribute);

	//addComponent(storage, CIRC, (void *)circle);

	writeSVGimage(storage, "file2.svg");

	deleteSVGimage(storage);

	char *str = showAttr("Emoji_grinning.svg", "svg.xsd", 0, "path");
	printf("%s\n", str);

	return 0;
}

void setListToEmpty(List *list)
{
	if (list == NULL)
	{
		return;
	}

	if (list->head == NULL && list->tail == NULL)
	{
		return;
	}

	Node *tmp;

	while (list->head != NULL)
	{
		list->head->data = NULL;
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}