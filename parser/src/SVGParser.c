#include "head.h"

void deleteAttribute(void *data)
{
	//printf("TEST");
	Attribute *attribute;
	attribute = data;

	free(attribute->name);
	free(attribute->value);
	free(attribute);
	//printf("DELETE ATTR\n");
}

char *attributeToString(void *data)
{
	//char *attributeReturn = "";
	//Attribute *otherAttribute = data;

	if (data == NULL)
	{
		return "";
	}
	else
	{
		char *attributeReturn = NULL;
		Attribute *otherAttribute = data;

		attributeReturn = malloc(((sizeof(char) * 21) + 1) + 1);
		strcpy(attributeReturn, "");
		strcat(attributeReturn, "Other attribute\nname=");

		//Name
		attributeReturn = realloc(attributeReturn, sizeof(char) * (strlen(attributeReturn) + strlen(otherAttribute->name)) + 1);
		strcat(attributeReturn, otherAttribute->name);
		//printf("OA: %s\n", attributeReturn);
		//printf("OA: %s\n", otherAttribute->name);

		attributeReturn = realloc(attributeReturn, (sizeof(char) * (strlen(attributeReturn) + 7)) + 1);
		strcat(attributeReturn, "\nvalue=");

		//Value
		attributeReturn = realloc(attributeReturn, sizeof(char) * (strlen(attributeReturn) + strlen(otherAttribute->value)) + 1);
		strcat(attributeReturn, otherAttribute->value);

		attributeReturn = realloc(attributeReturn, (sizeof(char) * (strlen(attributeReturn) + 2)) + 1);
		strcat(attributeReturn, "\n\n");

		//printf("%s", attributeReturn);

		return attributeReturn;
	}
}
int compareAttributes(const void *first, const void *second)
{
	return 0;
}

void deleteGroup(void *data)
{
	//this needs to be changed?
	Group *group;
	group = data;

	freeList(group->rectangles);
	freeList(group->circles);
	freeList(group->paths);
	freeList(group->otherAttributes);
	freeList(group->groups);

	/*
	if (getLength(group->groups) > 0)
	{
		printf("TEST TEST\n");

		if (group->groups->head->data != NULL)
		{
			//deleteGroup(group->groups->head->data);
			//Causing seg fault need to fix after
		}
	}
	*/

	//freeList(group->groups->head->data->otherAttributes);

	free(group);

	//printf("DELETE G\n");
}
char *groupToString(void *data)
{

	if (data == NULL)
	{
		return "";
	}
	else
	{

		char *groupReturn = malloc((sizeof(char) * 6) + 1 + 1);
		char *buffer = NULL;
		Group *group = data;
		strcpy(groupReturn, "");
		strcat(groupReturn, "Group\n");

		//printf("LENGTH: %d\n", group->paths->length);

		//printf("LENGTH: %d\n", getLength(group->paths));

		if (getLength(group->rectangles) > 0)
		{
			//strcpy(buffer, toString(group->rectangles));

			buffer = toString(group->rectangles);

			groupReturn = realloc(groupReturn, (sizeof(char) * strlen(groupReturn) + strlen(buffer)) + 1);
			strcat(groupReturn, buffer);
			//groupReturn = toString(group->rectangles);
			//printf("%s\n", buffer);
			free(buffer);
		}

		if (getLength(group->circles) > 0)
		{

			//strcpy(buffer, toString(group->circles));

			buffer = toString(group->circles);
			groupReturn = realloc(groupReturn, (sizeof(char) * strlen(groupReturn) + strlen(buffer)) + 1);
			//groupReturn = toString(group->circles);
			strcat(groupReturn, buffer);
			free(buffer);
		}

		if (getLength(group->paths) > 0)
		{
			//strcpy(buffer, toString(group->paths));

			buffer = toString(group->paths);
			groupReturn = realloc(groupReturn, (sizeof(char) * strlen(groupReturn) + strlen(buffer)) + 1);

			strcat(groupReturn, buffer);
			free(buffer);

			//groupReturn = toString(group->paths);
		}

		if (getLength(group->groups) > 0)
		{
			//strcpy(buffer, toString(group->groups));

			buffer = toString(group->groups);
			groupReturn = realloc(groupReturn, (sizeof(char) * strlen(groupReturn) + strlen(buffer)) + 1);
			strcat(groupReturn, buffer);
			free(buffer);

			//groupReturn = toString(group->groups);
		}

		if (getLength(group->otherAttributes) > 0)
		{
			buffer = toString(group->otherAttributes);
			//strcpy(buffer, toString(group->otherAttributes));
			groupReturn = realloc(groupReturn, (sizeof(char) * strlen(groupReturn) + strlen(buffer)) + 1);
			strcat(groupReturn, buffer);
			free(buffer);

			//groupReturn = toString(group->otherAttributes);
		}

		//printf("%s\n", groupReturn);

		//printf("TESTING TESTING\n");

		return groupReturn;
	}
}

int compareGroups(const void *first, const void *second)
{
	return 0;
}

void deleteRectangle(void *data)
{
	Rectangle *rect;
	rect = data;
	//printf("TEST");

	freeList(rect->otherAttributes);
	free(rect);

	//printf("DELETE RECT\n");
}
char *rectangleToString(void *data)
{
	/*
	char *rectReturn = "";
	char *otherAttributeReturn = NULL;
	char *buffer = malloc(sizeof(double) + 1);
	Rectangle *rect = data;
	*/

	if (data == NULL)
	{
		return "";
	}
	else
	{
		char *rectReturn = NULL;
		char *otherAttributeReturn = NULL;
		char *buffer = malloc(sizeof(double) + 1);
		Rectangle *rect = data;

		rectReturn = malloc((sizeof(char) * 12) + 1 + 1);
		strcpy(rectReturn, "");
		strcat(rectReturn, "Rectangle\nx=");

		//X
		sprintf(buffer, "%.2f", rect->x);

		//snprintf(buffer, sizeof(double) + 1,"%.2f", rect->x);

		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + strlen(buffer) + 1);
		strcat(rectReturn, buffer);

		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + 3 + 1);
		strcat(rectReturn, "\ny=");

		//Y
		sprintf(buffer, "%.2f", rect->y);
		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + strlen(buffer) + 1);
		strcat(rectReturn, buffer);

		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + 7 + 1);
		strcat(rectReturn, "\nwidth=");

		//Width
		sprintf(buffer, "%.2f", rect->width);
		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + strlen(buffer) + 1);
		strcat(rectReturn, buffer);

		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + 8 + 1);
		strcat(rectReturn, "\nheight=");

		//Height
		sprintf(buffer, "%.2f", rect->height);
		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + strlen(buffer) + 1);
		strcat(rectReturn, buffer);

		//Units
		if (strlen(rect->units) > 0)
		{
			rectReturn = realloc(rectReturn, (sizeof(char) * (strlen(rectReturn) + 7)) + 1);
			strcat(rectReturn, "\nunits=");
			rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn)) + strlen(rect->units) + 1);
			strcat(rectReturn, rect->units);
		}

		rectReturn = realloc(rectReturn, (sizeof(char) * strlen(rectReturn) + 1) + 1);
		strcat(rectReturn, "\n");

		/*
		if (getLength(rect->otherAttributes) > 0)
		{
			otherAttributeReturn = toString(rect->otherAttributes);
			rectReturn = realloc(rectReturn, (sizeof(char) * (strlen(rectReturn) + strlen(otherAttributeReturn))) + 1);
			strcat(rectReturn, otherAttributeReturn);
		}
		*/

		otherAttributeReturn = toString(rect->otherAttributes); // the error is here?
		rectReturn = realloc(rectReturn, (sizeof(char) * (strlen(rectReturn) + strlen(otherAttributeReturn))) + 1);
		strcat(rectReturn, otherAttributeReturn);

		//printf("%s", rectReturn);

		free(otherAttributeReturn);
		free(buffer);

		return rectReturn;
	}
}
int compareRectangles(const void *first, const void *second)
{
	return 0;
}

void deleteCircle(void *data)
{
	Circle *circle;
	circle = data;
	freeList(circle->otherAttributes);
	free(circle);

	//printf("DELETE CIRCLE\n");
}

char *circleToString(void *data)
{
	/*
	char *circleReturn = "";
	char *otherAttributeReturn = NULL;
	char *buffer = malloc(sizeof(double) + 1);
	Circle *circle = data;
	*/

	if (data == NULL)
	{
		return "";
	}
	else
	{
		char *circleReturn = NULL;
		char *otherAttributeReturn = NULL;
		char *buffer = malloc(sizeof(double) + 1);
		Circle *circle = data;

		circleReturn = malloc((sizeof(char) * 10) + 1 + 1);
		strcpy(circleReturn, "");
		strcat(circleReturn, "Circle\ncx=");

		//X
		sprintf(buffer, "%.2f", circle->cx); // change decimal places?
		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + strlen(buffer) + 1);
		strcat(circleReturn, buffer);

		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + 4 + 1);
		strcat(circleReturn, "\ncy=");

		//Y
		sprintf(buffer, "%.2f", circle->cy);
		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + strlen(buffer) + 1);
		strcat(circleReturn, buffer);

		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + 3 + 1);
		strcat(circleReturn, "\nr=");

		//Width
		sprintf(buffer, "%.2f", circle->r);
		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + strlen(buffer) + 1);
		strcat(circleReturn, buffer);

		//Units
		if (strlen(circle->units) > 0)
		{
			circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + 7 + 1);
			strcat(circleReturn, "\nunits=");
			circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn)) + strlen(circle->units) + 1);
			strcat(circleReturn, circle->units);
		}

		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn) + 1) + 1);
		strcat(circleReturn, "\n");

		otherAttributeReturn = toString(circle->otherAttributes);

		circleReturn = realloc(circleReturn, (sizeof(char) * strlen(circleReturn) + strlen(otherAttributeReturn)) + 1);
		strcat(circleReturn, otherAttributeReturn);

		//printf("%s", circleReturn);
		free(otherAttributeReturn);
		free(buffer);

		return circleReturn;
	}
}
int compareCircles(const void *first, const void *second)
{
	return 0;
}

void deletePath(void *data)
{
	Path *path;
	path = data;
	//printf("TEST");

	free(path->data);
	freeList(path->otherAttributes);
	free(path); //these might not be needed?

	//printf("DELETE PATH\n");
}
char *pathToString(void *data)
{
	/*
	char *pathReturn = "";
	char *otherAttributeReturn = NULL;
	Path *path = data;
	*/

	if (data == NULL)
	{
		return "";
	}
	else
	{
		char *pathReturn = NULL;
		char *otherAttributeReturn = NULL;
		Path *path = data;

		pathReturn = malloc((sizeof(char) * 7) + 1 + 1);
		strcpy(pathReturn, "");
		strcat(pathReturn, "Path\nd=");

		//data
		pathReturn = realloc(pathReturn, (sizeof(char) * strlen(pathReturn)) + strlen(path->data) + 1);
		strcat(pathReturn, path->data);

		pathReturn = realloc(pathReturn, (sizeof(char) * strlen(pathReturn) + 2) + 1);
		strcat(pathReturn, "\n\n");

		otherAttributeReturn = toString(path->otherAttributes);
		pathReturn = realloc(pathReturn, (sizeof(char) * strlen(pathReturn) + strlen(otherAttributeReturn)) + 1);
		strcat(pathReturn, otherAttributeReturn);

		//printf("%s", pathReturn);

		free(otherAttributeReturn);

		return pathReturn;
	}
}
int comparePaths(const void *first, const void *second)
{
	return 0;
}

static void findNamespace(xmlNode *cur_node, char array[256])
{
	xmlNs *nameSpaceNode = NULL;
	nameSpaceNode = cur_node->ns;
	char *nameSpaceString = NULL;

	if (nameSpaceNode != NULL)
	{
		nameSpaceString = (char *)nameSpaceNode->href;
		//printf("Namespace: %s\n", nameSpaceString);
		strncpy(array, nameSpaceString, 256);
	}
}

static void otherAttributeHelper(xmlNode *cur_node, Attribute *otherAttribute, List *otherAttributeList)
{
	xmlAttr *prop = NULL;
	char *buffer = NULL;
	char *attributeName = NULL;
	char *attributeValue = NULL;
	//List *otherAttributeList =  initializeList(attributeToString, deleteAttribute, compareAttributes);

	for (prop = cur_node->properties; prop; prop = prop->next)
	{
		if (prop != NULL)
		{
			//printf("TEST TEST\n");

			//any other properties from an attribute
			//printf("%s=", prop->name);
			//might have a loop to check for shit that is non-length and etc
			//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));

			Attribute *otherAttribute = malloc(sizeof(Attribute));

			attributeName = malloc(sizeof(char) * strlen((char *)prop->name) + 1);

			strcpy(attributeName, (char *)prop->name);
			otherAttribute->name = attributeName;
			//strcpy(otherAttribute->name, (char *)prop->name);
			//printf("ATTRIBUTE NAME: %s\n", otherAttribute->name);

			buffer = (char *)xmlNodeGetContent(prop->children);
			attributeValue = malloc(sizeof(char) * strlen(buffer) + 1);
			strcpy(attributeValue, buffer);
			otherAttribute->value = attributeValue;

			//printf("ATTRIBUTE VALUE: %s\n", otherAttribute->value);

			//printf("%s=\"%s\"\n", otherAttribute->name, otherAttribute->value);

			xmlFree(buffer);

			insertBack(otherAttributeList, otherAttribute);
		}
	}
	//printf("\n");
}

static void pathHelper(xmlNode *cur_node, Path *path, List *otherAttributeList)
{
	xmlAttr *prop = NULL;
	char *buffer = NULL;
	char *attributeName = NULL;
	char *attributeValue = NULL;
	char *pathData = NULL;

	//path = malloc(sizeof(Path));

	//List *otherAttributeList =  initializeList(attributeToString, deleteAttribute, compareAttributes);

	for (prop = cur_node->properties; prop; prop = prop->next)
	{
		if (prop != NULL)
		{
			//printf("TEST TEST\n");

			if (strcmp((char *)prop->name, "d") == 0)
			{
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));

				//path = malloc(sizeof(Path));

				buffer = (char *)xmlNodeGetContent(prop->children);
				//printf("%s\n", buffer);

				pathData = malloc((sizeof(char) * strlen(buffer)) + 1);

				strcpy(pathData, buffer);

				//printf("%s\n", pathData);

				path->data = pathData;

				//strcpy(string3, buffer);
				//printf("\nD VALUE IN PATH: %s\n", path->data);

				xmlFree(buffer);

				//this is only here for testing purposes
				//free(string3);
			}
			else
			{
				//any other properties from an attribute
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));

				Attribute *otherAttribute = malloc(sizeof(Attribute));

				attributeName = malloc(sizeof(char) * strlen((char *)prop->name) + 1);
				strcpy(attributeName, (char *)prop->name);
				otherAttribute->name = attributeName;
				//strcpy(otherAttribute->name, (char *)prop->name);
				//printf("ATTRIBUTE NAME: %s\n", otherAttribute->name);

				buffer = (char *)xmlNodeGetContent(prop->children);
				attributeValue = malloc(sizeof(char) * strlen(buffer) + 1);
				strcpy(attributeValue, buffer);
				otherAttribute->value = attributeValue;

				//printf("ATTRIBUTE VALUE: %s\n", otherAttribute->value);

				xmlFree(buffer);

				//printf("%s=\"%s\"\n", otherAttribute->name, otherAttribute->value);

				insertBack(otherAttributeList, otherAttribute);

				//path->otherAttributes = otherAttributeList;
			}
		}
	}
	//printf("\n");
}

static void circleHelper(xmlNode *cur_node, Circle *circle, List *otherAttributeList)
{
	xmlAttr *prop = NULL;
	char *buffer = NULL;
	char *units = NULL;
	char *attributeName = NULL;
	char *attributeValue = NULL;
	int check = 0;
	//List *otherAttributeList =  initializeList(attributeToString, deleteAttribute, compareAttributes);

	for (prop = cur_node->properties; prop; prop = prop->next)
	{
		if (prop != NULL)
		{
			//printf("TEST TEST\n");

			if (strcmp((char *)prop->name, "cx") == 0 /* check != 1 */)
			{
				//printf("TEST TEST\n");

				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				circle->cx = strtof(buffer, &units);
				//units = strtok(units, " ");

				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{
					units = strtok(units, " ");

					if (units != NULL)
					{
						//token = malloc(sizeof(char) * strlen(units) + 1);
						//strcpy(token, units);
						strcpy(circle->units, units);

						//free(token);
					}
					else
					{
						strcpy(circle->units, "");
					}
					//strncpy(rect->units, units, strlen(units));
					//strcpy(rect->units, units);

					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", circle->units);
				}
				//assign value here to list

				//reset buffer
				xmlFree(buffer);
			}
			else if (strcmp((char *)prop->name, "cy") == 0)
			{
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				circle->cy = strtof(buffer, &units);

				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{
					units = strtok(units, " ");

					if (units != NULL)
					{
						//token = malloc(sizeof(char) * strlen(units) + 1);
						//strcpy(token, units);
						strcpy(circle->units, units);

						//free(token);
					}
					else
					{
						strcpy(circle->units, "");
					}
					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", units);
				}

				xmlFree(buffer);
			}
			else if (strcmp((char *)prop->name, "r") == 0)
			{
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				circle->r = strtof(buffer, &units);
				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{
					units = strtok(units, " ");

					if (units != NULL)
					{
						//token = malloc(sizeof(char) * strlen(units) + 1);
						//strcpy(token, units);
						strcpy(circle->units, units);

						//free(token);
					}
					else
					{
						strcpy(circle->units, "");
					}
					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", units);
				}

				xmlFree(buffer);
			}
			else
			{
				//any other properties from an attribute
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));

				Attribute *otherAttribute = malloc(sizeof(Attribute));

				attributeName = malloc(sizeof(char) * strlen((char *)prop->name) + 1);
				strcpy(attributeName, (char *)prop->name);
				otherAttribute->name = attributeName;
				//strcpy(otherAttribute->name, (char *)prop->name);
				//printf("ATTRIBUTE NAME: %s\n", otherAttribute->name);

				buffer = (char *)xmlNodeGetContent(prop->children);
				attributeValue = malloc(sizeof(char) * strlen(buffer) + 1);
				strcpy(attributeValue, buffer);
				otherAttribute->value = attributeValue;

				//strcpy(otherAttribute->value, buffer);
				//value = atof(buffer);

				//printf("ATTRIBUTE VALUE: %s\n", otherAttribute->value);

				xmlFree(buffer);

				//printf("%s=\"%s\"\n", otherAttribute->name, otherAttribute->value);

				insertBack(otherAttributeList, otherAttribute);
			}
		}
	}
	//printf("\n");
}

static void rectHelper(xmlNode *cur_node, Rectangle *rect, List *otherAttributeList)
{
	xmlAttr *prop = NULL;
	char *buffer = NULL;
	char *units = NULL;
	char *attributeName = NULL;
	char *attributeValue = NULL;
	int check = 0;
	//List *otherAttributeList =  initializeList(attributeToString, deleteAttribute, compareAttributes);

	for (prop = cur_node->properties; prop; prop = prop->next)
	{
		if (prop != NULL)
		{
			if (strcmp((char *)prop->name, "x") == 0 /* check != 1 */)
			{
				//printf("TEST TEST\n");
				//printf("RECT HELPER RUN\n");

				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				rect->x = strtof(buffer, &units);
				//units = strtok(units, " ");

				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{
					units = strtok(units, " ");

					if (units != NULL)
					{
						strcpy(rect->units, units);
					}
					else
					{
						strcpy(rect->units, "");
					}
					//strncpy(rect->units, units, strlen(units));
					//strcpy(rect->units, units);

					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", rect->units);
				}
				//assign value here to list

				//reset buffer
				xmlFree(buffer);
			}
			else if (strcmp((char *)prop->name, "y") == 0)
			{
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				rect->y = strtof(buffer, &units);

				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{
					units = strtok(units, " ");

					if (units != NULL)
					{
						strcpy(rect->units, units);
					}
					else
					{
						strcpy(rect->units, "");
					}
					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", units);
				}

				xmlFree(buffer);
			}
			else if (strcmp((char *)prop->name, "width") == 0)
			{
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				rect->width = strtof(buffer, &units);
				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{

					units = strtok(units, " ");

					if (units != NULL)
					{
						strcpy(rect->units, units);
					}
					else
					{
						strcpy(rect->units, "");
					}
					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", units);
				}

				xmlFree(buffer);
			}
			else if (strcmp((char *)prop->name, "height") == 0)
			{
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));
				buffer = (char *)xmlNodeGetContent(prop->children);
				rect->height = strtof(buffer, &units);
				//printf("Float Value: %f\n", value);

				if (units != NULL && check != 1)
				{
					units = strtok(units, " ");

					if (units != NULL)
					{
						strcpy(rect->units, units);
					}
					else
					{
						strcpy(rect->units, "");
					}
					units = NULL;
					check = 1;
					//printf("Units Value: %s\n", units);
				}

				xmlFree(buffer);
			}
			else
			{
				//any other properties from an attribute
				//printf("%s=", prop->name);
				//might have a loop to check for shit that is non-length and etc
				//printf("\"%s\" ", (char *)xmlNodeGetContent(prop->children));

				Attribute *otherAttribute = malloc(sizeof(Attribute));

				attributeName = malloc(sizeof(char) * strlen((char *)prop->name) + 1);
				strcpy(attributeName, (char *)prop->name);
				otherAttribute->name = attributeName;
				//printf("NAME IN HELPER: %s\n", otherAttribute->name);

				//strcpy(otherAttribute->name, (char *)prop->name);
				//printf("ATTRIBUTE NAME: %s\n", otherAttribute->name);

				buffer = (char *)xmlNodeGetContent(prop->children);
				attributeValue = malloc(sizeof(char) * strlen(buffer) + 1);
				strcpy(attributeValue, buffer);
				otherAttribute->value = attributeValue;

				//strcpy(otherAttribute->value, buffer);
				//value = atof(buffer);

				//printf("ATTRIBUTE VALUE: %s\n", otherAttribute->value);
				xmlFree(buffer);

				//printf("%s=\"%s\"\n", otherAttribute->name, otherAttribute->value);

				insertBack(otherAttributeList, otherAttribute);
			}
		}
	}
	//printf("\n");
}

// for title and desc
// current node's children
static void helper2(xmlNode *cur_node, char array[256])
{
	xmlNode *desc = NULL;

	for (desc = cur_node->children; desc; desc = desc->next)
	{
		if (desc != NULL)
		{
			//might need an if statement for later like helper1
			//printf("\"%s\" ", (char *)desc->content);
			strncpy(array, (char *)desc->content, 256);
		}
	}
	//printf("\n");
}

static void groupHelper(xmlNode *a_node, SVGimage *storage, Group *group /* , List *otherAttributeList */)
{
	xmlNode *cur_node = NULL;
	group->rectangles = initializeList(rectangleToString, deleteRectangle, compareRectangles);
	group->circles = initializeList(circleToString, deleteCircle, compareCircles);
	group->paths = initializeList(pathToString, deletePath, comparePaths);
	group->groups = initializeList(groupToString, deleteGroup, compareGroups);
	//group->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

	//Group *groupInfo = malloc(sizeof(Group));

	Attribute *otherAttributeInfo = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next)
	{
		if (cur_node->type == XML_ELEMENT_NODE)
		{
			if (strcmp((char *)cur_node->name, "rect") == 0)
			{
				//Might make a single helper function for this
				Rectangle *rectInfo = malloc(sizeof(Rectangle));
				List *otherRectAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
				//printf("node type: Element, name: %s\n", cur_node->name);
				rectHelper(cur_node, rectInfo, otherRectAttributes);
				rectInfo->otherAttributes = otherRectAttributes;
				insertBack(group->rectangles, rectInfo);

				//printf("num of rects in groupHelper: %d\n", getLength(group->rectangles));
			}
			else if (strcmp((char *)cur_node->name, "circle") == 0)
			{
				//printf("TEST TEST TEST CIRCLE\n");

				Circle *circleInfo = malloc(sizeof(Circle));
				List *otherCirlceAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
				//printf("node type: Element, name: %s\n", cur_node->name);
				circleHelper(cur_node, circleInfo, otherCirlceAttributes);
				circleInfo->otherAttributes = otherCirlceAttributes;
				insertBack(group->circles, circleInfo);
			}
			else if (strcmp((char *)cur_node->name, "path") == 0)
			{
				//printf("TEST TEST TEST PATH\n");

				Path *pathInfo = malloc(sizeof(Path));
				List *otherPathAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

				//printf("node type: Element, name: %s\n", cur_node->name);
				pathHelper(cur_node, pathInfo, otherPathAttributes);
				pathInfo->otherAttributes = otherPathAttributes;
				insertBack(group->paths, pathInfo);
			}
			else if (strcmp((char *)cur_node->name, "g") == 0) //move this to bottom?
			{
				//printf("TEST TEST TEST GROUP\n");

				Group *groupInfo = malloc(sizeof(Group));

				groupInfo->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes); //dont need this?

				//printf("node type: Element, name: %s\n", cur_node->name);
				//helper1(cur_node, group);
				//print_element_names(cur_node->children, storage);

				//printf("TEST TEST TEST\n");

				otherAttributeHelper(cur_node, otherAttributeInfo, groupInfo->otherAttributes);

				groupHelper(cur_node->children, storage, groupInfo /*, otherGroupAttributes */);
				//groupInfo->otherAttributes = otherGroupAttributes;
				insertBack(group->groups, groupInfo);

				//printf("num of groups in groups: %d\n", getLength(group->groups));
			}
			else
			{
				//Attribute *otherAttributeInfo = malloc(sizeof(Attribute)); //might need to move this outside
				//List *otherGeneralAttributes =  initializeList(attributeToString, deleteAttribute, compareAttributes);
				//printf("node type: Element, name: %s\n", cur_node->name);

				//printf("TEST TEST TEST OTHER\n");
				otherAttributeHelper(cur_node, otherAttributeInfo, group->otherAttributes);

				//insertBack(otherAttributeList, otherAttributeInfo);
				//otherAttributeInfo->otherAttributes = otherGeneralAttributes;
			}
		}
	}
}

static void print_element_names(xmlNode *a_node, SVGimage *storage, List *rectList, List *circleList, List *pathList, List *groupList, List *otherAttributeList)
{

	xmlNode *cur_node = NULL;
	Attribute *otherAttributeInfo = NULL;

	//might be this for loop
	for (cur_node = a_node; cur_node; cur_node = cur_node->next)
	{

		if (cur_node->type == XML_ELEMENT_NODE)
		{
			if (strcmp((char *)cur_node->name, "svg") == 0)
			{
				//Attribute *otherAttributeInfo = malloc(sizeof(Attribute));
				otherAttributeHelper(cur_node, otherAttributeInfo, otherAttributeList); //looks like this worked?

				if (strlen(storage->namespace) == 0)
				{
					findNamespace(cur_node, storage->namespace);
					//printf("NAMESPACE: %s\n", storage->namespace);
				}

				/*
				findNamespace(cur_node, storage->namespace);
				printf("NAMESPACE: %s\n", storage->namespace);
				*/
			}
			else if (strcmp((char *)cur_node->name, "rect") == 0)
			{
				//Might make a single helper function for this
				Rectangle *rectInfo = malloc(sizeof(Rectangle));
				List *otherRectAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
				//printf("node type: Element, name: %s\n", cur_node->name);
				rectHelper(cur_node, rectInfo, otherRectAttributes);
				rectInfo->otherAttributes = otherRectAttributes;

				//printf("rect info x: %f\n", rectInfo->x);

				insertBack(rectList, rectInfo);

				//printf("num of rects in rectHelper: %d\n", getLength(rectList));
			}
			else if (strcmp((char *)cur_node->name, "circle") == 0)
			{
				Circle *circleInfo = malloc(sizeof(Circle));
				List *otherCirlceAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
				//printf("node type: Element, name: %s\n", cur_node->name);
				circleHelper(cur_node, circleInfo, otherCirlceAttributes);
				circleInfo->otherAttributes = otherCirlceAttributes;
				insertBack(circleList, circleInfo);
			}
			else if (strcmp((char *)cur_node->name, "path") == 0)
			{
				Path *pathInfo = malloc(sizeof(Path));
				//Path *pathInfo = NULL;

				List *otherPathAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

				//printf("node type: Element, name: %s\n", cur_node->name);
				pathHelper(cur_node, pathInfo, otherPathAttributes);
				pathInfo->otherAttributes = otherPathAttributes;
				insertBack(pathList, pathInfo);
			}
			else if (strcmp((char *)cur_node->name, "g") == 0)
			{
				Group *groupInfo = malloc(sizeof(Group));
				groupInfo->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
				//List *otherGroupAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes); // i dont think i need this

				//printf("node type: Element, name: %s\n", cur_node->name);
				//helper1(cur_node, group);
				//print_element_names(cur_node->children, storage);
				otherAttributeHelper(cur_node, otherAttributeInfo, groupInfo->otherAttributes);

				groupHelper(cur_node->children, storage, groupInfo /* , otherGroupAttributes */);

				//groupInfo->otherAttributes = otherGroupAttributes;

				insertBack(groupList, groupInfo);

				//printf("LENGTH OF GROUP: %d\n", groupList->length);
			}
			else if (strcmp((char *)cur_node->name, "title") == 0)
			{
				//printf("node type: Element, name: %s\n", cur_node->name);

				if (strlen(storage->title) == 0)
				{
					helper2(cur_node, storage->title);
					//printf("TITLE: %s\n", storage->title);
				}

				/*
				helper2(cur_node, storage->title);
				printf("TITLE: %s\n", storage->title);
				*/
			}
			else if (strcmp((char *)cur_node->name, "desc") == 0)
			{
				//printf("node type: Element, name: %s\n", cur_node->name);

				if (strlen(storage->description) == 0)
				{
					helper2(cur_node, storage->description);
					//printf("DESC: %s\n", storage->description);
				}

				/*
				helper2(cur_node, storage->description);
				printf("DESC: %s\n", storage->description);
				*/
			}
			else
			{
				//Attribute *otherAttributeInfo = malloc(sizeof(Attribute)); //might need to move this outside
				//List *otherGeneralAttributes =  initializeList(attributeToString, deleteAttribute, compareAttributes);

				//printf("node type: Element, name: %s\n", cur_node->name);
				otherAttributeHelper(cur_node, otherAttributeInfo, otherAttributeList);
				//insertBack(otherAttributeList, otherAttributeInfo);
			}
		}
	}

	//next iteration of the node
	if (a_node->children != NULL)
	{
		print_element_names(a_node->children, storage, rectList, circleList, pathList, groupList, otherAttributeList);
	}
}

SVGimage *createSVGimage(char *fileName)
{
	xmlDoc *file = NULL;
	xmlNode *root = NULL;
	SVGimage *storage = malloc(sizeof(SVGimage));

	storage->namespace[0] = '\0';
	storage->title[0] = '\0';
	storage->description[0] = '\0';

	List *rectList = initializeList(rectangleToString, deleteRectangle, compareRectangles);
	List *circleList = initializeList(circleToString, deleteCircle, compareCircles);
	List *pathList = initializeList(pathToString, deletePath, comparePaths);
	List *groupList = initializeList(groupToString, deleteGroup, compareGroups);
	List *otherAttributeList = initializeList(attributeToString, deleteAttribute, compareAttributes);

	file = xmlReadFile(fileName, NULL, 0);

	//apparently we dont need this

	if (file == NULL)
	{
		printf("xml cannot be parsed\n");

		free(storage);
		xmlFreeDoc(file);
		xmlCleanupParser();
		return NULL;
	}

	root = xmlDocGetRootElement(file);

	print_element_names(root, storage, rectList, circleList, pathList, groupList, otherAttributeList);

	//Node *item = rectList->head;

	storage->rectangles = rectList;
	storage->circles = circleList;
	storage->paths = pathList;
	storage->groups = groupList;
	storage->otherAttributes = otherAttributeList;

	//printf("NAMESPACE: %s\n", storage->namespace);
	//printf("TITLE: %s\n", storage->title);
	//printf("DESCRIPTION: %s\n", storage->description);

	//rectangleToString(storage->rectangles->head);

	xmlFreeDoc(file);

	xmlCleanupParser();

	return storage;
}

char *SVGimageToString(SVGimage *img)
{
	char *rect = NULL;
	char *circle = NULL;
	char *path = NULL;
	char *group = NULL;
	char *otherAttribute = NULL;
	char *temp = malloc(sizeof(char) + 1);
	strcpy(temp, "");

	if (getLength(img->rectangles) > 0)
	{
		rect = toString(img->rectangles);
		temp = realloc(temp, sizeof(char) * strlen(temp) + strlen(rect) + 1);
		strcat(temp, rect);
		free(rect);
	}
	if (getLength(img->circles) > 0)
	{
		circle = toString(img->circles);
		temp = realloc(temp, sizeof(char) * strlen(temp) + strlen(circle) + 1);
		strcat(temp, circle);
		free(circle);
	}

	if (getLength(img->paths) > 0)
	{
		path = toString(img->paths);
		temp = realloc(temp, sizeof(char) * strlen(temp) + strlen(path) + 1);
		strcat(temp, path);
		free(path);
	}

	if (getLength(img->groups) > 0)
	{
		group = toString(img->groups);
		temp = realloc(temp, sizeof(char) * strlen(temp) + strlen(group) + 1);
		strcat(temp, group);
		free(group);
	}

	if (getLength(img->otherAttributes) > 0)
	{
		otherAttribute = toString(img->otherAttributes);
		temp = realloc(temp, sizeof(char) * strlen(temp) + strlen(otherAttribute) + 1);
		strcat(temp, otherAttribute);
		free(otherAttribute);
	}

	/*
	rect = toString(img->rectangles);
	circle = toString(img->circles);
	path = toString(img->paths);
	group = toString(img->groups);
	otherAttribute = toString(img->otherAttributes);
	*/

	//printf("rect: %ld\n", strlen(rect));

	//printf("ld\n", strlen(rect) + strlen(circle) + strlen(path) + strlen(group) + strlen(otherAttribute) + 2);

	//temp = malloc(sizeof(char) * (strlen(rect) + strlen(circle) + strlen(path) + strlen(group) + strlen(otherAttribute) + 1) + 1);
	//temp = malloc(sizeof(char) * 1001);
	/*
	strcpy(temp, "");
	strcat(temp, rect);
	strcat(temp, circle);
	strcat(temp, path);
	strcat(temp, group);
	strcat(temp, otherAttribute);
	*/
	//printf("%s", rect);
	//printf("%s", circle);
	//printf("%s", path);
	//printf("%s", group);
	//printf("%s", otherAttribute);

	/*
	free(rect);
	free(circle);
	free(path);
	free(group);
	free(otherAttribute);
	*/

	return temp;
}

void deleteSVGimage(SVGimage *img)
{
	//Node *innerGroupNode = NULL;
	//List *innerGroupList = NULL;
	//Group *group = NULL;
	//need to free SVGimageToString

	/*
	if (img != NULL)
	{
		freeList(img->rectangles);
		freeList(img->circles);
		freeList(img->paths);
		freeList(img->otherAttributes);

		
		if (img->groups->head != NULL)
		{
			group = img->groups->head->data;
			//printf("TEST TEST\n");

            //innerGroup = img->groups;
            //innerGroup = innerGroup->groups;
			freeList(img->groups);
		}
		else
		{
			freeList(img->groups);
            //printf("TEST TEST\n");
		}
		
		freeList(img->groups);

		free(img);
	}
	*/

	//maybe call free on svg string to image here

	if (img != NULL)
	{
		freeList(img->rectangles);
		freeList(img->circles);
		freeList(img->paths);
		freeList(img->otherAttributes);
		freeList(img->groups);

		free(img);
	}
}

List *getCircles(SVGimage *img)
{
	if (img != NULL)
	{
		List *circleReturnList = initializeList(circleToString, deleteCircle, compareCircles);

		ListIterator curNode = createIterator(img->circles);
		ListIterator *nodePtr = &curNode;
		Circle *circle;

		while (nodePtr->current != NULL)
		{
			circle = nodePtr->current->data;
			/*
			//new circle for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY
			Circle *newCircle = malloc(sizeof(Circle));

			newCircle->cx = circle->cx;
			newCircle->cy = circle->cy;
			newCircle->r = circle->r;
			strcpy(newCircle->units, circle->units);

			List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			if (getLength(circle->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(circle->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttribute;

				while (nodePtr2->current != NULL)
				{
					otherAttribute = nodePtr2->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(otherAttributes, newOtherAttribute);

					nextElement(nodePtr2);
				}
			}

			newCircle->otherAttributes = otherAttributes;
			insertBack(circleReturnList, newCircle);
			*/

			insertBack(circleReturnList, circle);
			nextElement(nodePtr);
		}

		if (getLength(img->groups) > 0)
		{
			getGroupCircles(circleReturnList, img->groups);
		}

		return circleReturnList;
	}

	return NULL;
}

void getGroupCircles(List *circleReturnList, List *groupList)
{
	//group
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		ListIterator curNode3 = createIterator(group->circles);
		ListIterator *nodePtr3 = &curNode3;
		Circle *circle;

		while (nodePtr3->current != NULL)
		{
			circle = nodePtr3->current->data;

			/*
			//new cirlce for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY
			Circle *newCircle = malloc(sizeof(Circle));

			newCircle->cx = circle->cx;
			newCircle->cy = circle->cy;
			newCircle->r = circle->r;
			strcpy(newCircle->units, circle->units);

			List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			if (getLength(circle->otherAttributes) > 0)
			{
				ListIterator curNode4 = createIterator(circle->otherAttributes);
				ListIterator *nodePtr4 = &curNode4;
				Attribute *otherAttribute;

				while (nodePtr4->current != NULL)
				{
					otherAttribute = nodePtr4->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(otherAttributes, newOtherAttribute);

					nextElement(nodePtr4);
				}
			}
			newCircle->otherAttributes = otherAttributes;
			insertBack(circleReturnList, newCircle);
			*/

			insertBack(circleReturnList, circle);
			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			getGroupCircles(circleReturnList, group->groups);
		}
		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}
}

List *getGroups(SVGimage *img)
{
	if (img != NULL)
	{
		List *groupReturnList = initializeList(groupToString, deleteGroup, compareGroups);

		ListIterator curNode5 = createIterator(img->groups);
		ListIterator *nodePtr5 = &curNode5;
		Group *group;

		while (nodePtr5->current != NULL)
		{
			group = nodePtr5->current->data;

			/*
			//new group for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY ============================================================================
			Group *newGroup = malloc(sizeof(Group));

			newGroup->rectangles = initializeList(rectangleToString, deleteRectangle, compareRectangles);
			newGroup->circles = initializeList(circleToString, deleteCircle, compareCircles);
			newGroup->paths = initializeList(pathToString, deletePath, comparePaths);
			newGroup->groups = initializeList(groupToString, deleteGroup, compareGroups);
			newGroup->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			//List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);
			//rects
			
			if (getLength(group->rectangles) > 0)
			{
				ListIterator curNode = createIterator(group->rectangles);
				ListIterator *nodePtr = &curNode;
				Rectangle *rect;

				while (nodePtr->current != NULL)
				{
					rect = nodePtr->current->data;

					//new rect for new list
					Rectangle *newRect = malloc(sizeof(Rectangle));

					newRect->x = rect->x;
					newRect->y = rect->y;
					newRect->width = rect->width;
					newRect->height = rect->height;
					strcpy(newRect->units, rect->units);

					List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

					if (getLength(rect->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(rect->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttribute;

						while (nodePtr2->current != NULL)
						{
							otherAttribute = nodePtr2->current->data;

							Attribute *newOtherAttribute = malloc(sizeof(Attribute));
							newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
							strcpy(newOtherAttribute->name, otherAttribute->name);
							newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
							strcpy(newOtherAttribute->value, otherAttribute->value);
							insertBack(otherAttributes, newOtherAttribute);

							nextElement(nodePtr2);
						}
					}

					newRect->otherAttributes = otherAttributes;
					insertBack(newGroup->rectangles, newRect);

					//insertBack(rectReturnList, rect);
					nextElement(nodePtr);
				}
			}

			
			//circles
			if (getLength(group->circles) > 0)
			{
				ListIterator curNode = createIterator(group->circles);
				ListIterator *nodePtr = &curNode;
				Circle *circle;

				while (nodePtr->current != NULL)
				{
					circle = nodePtr->current->data;

					//new circle for new list
					Circle *newCircle = malloc(sizeof(Circle));

					newCircle->cx = circle->cx;
					newCircle->cy = circle->cy;
					newCircle->r = circle->r;
					strcpy(newCircle->units, circle->units);

					List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

					if (getLength(circle->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(circle->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttribute;

						while (nodePtr2->current != NULL)
						{
							otherAttribute = nodePtr2->current->data;

							Attribute *newOtherAttribute = malloc(sizeof(Attribute));
							newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
							strcpy(newOtherAttribute->name, otherAttribute->name);
							newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
							strcpy(newOtherAttribute->value, otherAttribute->value);
							insertBack(otherAttributes, newOtherAttribute);

							nextElement(nodePtr2);
						}
					}

					newCircle->otherAttributes = otherAttributes;
					insertBack(newGroup->circles, newCircle);
					nextElement(nodePtr);
				}
			}

			//paths
			if (getLength(group->paths) > 0)
			{
				ListIterator curNode = createIterator(group->paths);
				ListIterator *nodePtr = &curNode;
				Path *path;

				while (nodePtr->current != NULL)
				{
					path = nodePtr->current->data;

					//new path for new list
					Path *newPath = malloc(sizeof(Path));
					newPath->data = malloc(sizeof(char) * strlen(path->data) + 1);
					strcpy(newPath->data, path->data);

					List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

					if (getLength(path->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(path->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttribute;

						while (nodePtr2->current != NULL)
						{
							otherAttribute = nodePtr2->current->data;

							Attribute *newOtherAttribute = malloc(sizeof(Attribute));
							newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
							strcpy(newOtherAttribute->name, otherAttribute->name);
							newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
							strcpy(newOtherAttribute->value, otherAttribute->value);
							insertBack(otherAttributes, newOtherAttribute);

							nextElement(nodePtr2);
						}
					}
					newPath->otherAttributes = otherAttributes;
					insertBack(newGroup->paths, newPath);

					//insertBack(pathReturnList, path);
					nextElement(nodePtr);
				}
			}

			//other attributes
			if (getLength(group->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(group->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttribute;

				while (nodePtr2->current != NULL)
				{
					otherAttribute = nodePtr2->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(newGroup->otherAttributes, newOtherAttribute);

					nextElement(nodePtr2);
				}
			}
			*/

			/*
			if (getLength(group->groups) > 0)
			{
				getGroupGroups(groupReturnList, group->groups);
			}
			*/

			//newGroup->otherAttributes = otherAttributes;
			//insertBack(groupReturnList, newGroup);

			//=================================================================================================
			insertBack(groupReturnList, group);
			nextElement(nodePtr5);
		}

		if (getLength(img->groups) > 0)
		{
			getGroupGroups(groupReturnList, img->groups);
		}

		return groupReturnList;
	}

	return NULL;
}

void getGroupGroups(List *groupReturnList, List *groupList)
{
	//group
	ListIterator curNode5 = createIterator(groupList);
	ListIterator *nodePtr5 = &curNode5;
	Group *group;

	while (nodePtr5->current != NULL)
	{
		group = nodePtr5->current->data;

		ListIterator curNode3 = createIterator(group->groups);
		ListIterator *nodePtr3 = &curNode3;
		Group *group2;

		while (nodePtr3->current != NULL)
		{
			group2 = nodePtr3->current->data;

			/*
			//new group for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY ============================================================================
			Group *newGroup = malloc(sizeof(Group));

			newGroup->rectangles = initializeList(rectangleToString, deleteRectangle, compareRectangles);
			newGroup->circles = initializeList(circleToString, deleteCircle, compareCircles);
			newGroup->paths = initializeList(pathToString, deletePath, comparePaths);
			newGroup->groups = initializeList(groupToString, deleteGroup, compareGroups);
			newGroup->otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			//List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			
			//rects
			if (getLength(group2->rectangles) > 0)
			{
				ListIterator curNode = createIterator(group2->rectangles);
				ListIterator *nodePtr = &curNode;
				Rectangle *rect;

				while (nodePtr->current != NULL)
				{
					rect = nodePtr->current->data;

					//new rect for new list
					Rectangle *newRect = malloc(sizeof(Rectangle));

					newRect->x = rect->x;
					newRect->y = rect->y;
					newRect->width = rect->width;
					newRect->height = rect->height;
					strcpy(newRect->units, rect->units);

					List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

					if (getLength(rect->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(rect->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttribute;

						while (nodePtr2->current != NULL)
						{
							otherAttribute = nodePtr2->current->data;

							Attribute *newOtherAttribute = malloc(sizeof(Attribute));
							newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
							strcpy(newOtherAttribute->name, otherAttribute->name);
							newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
							strcpy(newOtherAttribute->value, otherAttribute->value);
							insertBack(otherAttributes, newOtherAttribute);

							nextElement(nodePtr2);
						}
					}

					newRect->otherAttributes = otherAttributes;
					insertBack(newGroup->rectangles, newRect);

					//insertBack(rectReturnList, rect);
					nextElement(nodePtr);
				}
			}

			//circles
			if (getLength(group2->circles) > 0)
			{
				ListIterator curNode = createIterator(group2->circles);
				ListIterator *nodePtr = &curNode;
				Circle *circle;

				while (nodePtr->current != NULL)
				{
					circle = nodePtr->current->data;

					//new circle for new list
					Circle *newCircle = malloc(sizeof(Circle));

					newCircle->cx = circle->cx;
					newCircle->cy = circle->cy;
					newCircle->r = circle->r;
					strcpy(newCircle->units, circle->units);

					List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

					if (getLength(circle->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(circle->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttribute;

						while (nodePtr2->current != NULL)
						{
							otherAttribute = nodePtr2->current->data;

							Attribute *newOtherAttribute = malloc(sizeof(Attribute));
							newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
							strcpy(newOtherAttribute->name, otherAttribute->name);
							newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
							strcpy(newOtherAttribute->value, otherAttribute->value);
							insertBack(otherAttributes, newOtherAttribute);

							nextElement(nodePtr2);
						}
					}

					newCircle->otherAttributes = otherAttributes;
					insertBack(newGroup->circles, newCircle);
					nextElement(nodePtr);
				}
			}

			//paths
			if (getLength(group2->paths) > 0)
			{
				ListIterator curNode = createIterator(group2->paths);
				ListIterator *nodePtr = &curNode;
				Path *path;

				while (nodePtr->current != NULL)
				{
					path = nodePtr->current->data;

					//new path for new list
					Path *newPath = malloc(sizeof(Path));
					newPath->data = malloc(sizeof(char) * strlen(path->data) + 1);
					strcpy(newPath->data, path->data);

					List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

					if (getLength(path->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(path->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttribute;

						while (nodePtr2->current != NULL)
						{
							otherAttribute = nodePtr2->current->data;

							Attribute *newOtherAttribute = malloc(sizeof(Attribute));
							newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
							strcpy(newOtherAttribute->name, otherAttribute->name);
							newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
							strcpy(newOtherAttribute->value, otherAttribute->value);
							insertBack(otherAttributes, newOtherAttribute);

							nextElement(nodePtr2);
						}
					}
					newPath->otherAttributes = otherAttributes;
					insertBack(newGroup->paths, newPath);

					//insertBack(pathReturnList, path);
					nextElement(nodePtr);
				}
			}

			//other attributes
			if (getLength(group2->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(group2->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttribute;

				while (nodePtr2->current != NULL)
				{
					otherAttribute = nodePtr2->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(newGroup->otherAttributes, newOtherAttribute);

					nextElement(nodePtr2);
				}
			}
			*/

			/*
			if (getLength(group->groups) > 0)
			{
				getGroupGroups(groupReturnList, img->groups);
			}
			*/

			//newGroup->otherAttributes = otherAttributes;
			//insertBack(groupReturnList, newGroup);

			//=================================================================================================
			insertBack(groupReturnList, group2);
			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			getGroupGroups(groupReturnList, group->groups);
		}
		nextElement(nodePtr5);
	}
}

List *getPaths(SVGimage *img)
{
	//printf("TEST");

	if (img != NULL)
	{
		List *pathReturnList = initializeList(pathToString, deletePath, comparePaths);

		ListIterator curNode = createIterator(img->paths);
		ListIterator *nodePtr = &curNode;
		Path *path;

		while (nodePtr->current != NULL)
		{
			path = nodePtr->current->data;

			/*
			//new path for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY
			Path *newPath = malloc(sizeof(Path));
			newPath->data = malloc(sizeof(char) * strlen(path->data) + 1);
			strcpy(newPath->data, path->data);

			List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			if (getLength(path->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(path->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttribute;

				while (nodePtr2->current != NULL)
				{
					otherAttribute = nodePtr2->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(otherAttributes, newOtherAttribute);

					nextElement(nodePtr2);
				}
			}
			newPath->otherAttributes = otherAttributes;
			insertBack(pathReturnList, newPath);
			*/

			insertBack(pathReturnList, path);
			nextElement(nodePtr);
		}

		if (getLength(img->groups) > 0)
		{
			getGroupPaths(pathReturnList, img->groups);
		}

		return pathReturnList;
	}

	return NULL;
}

void getGroupPaths(List *pathReturnList, List *groupList)
{
	//group
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		ListIterator curNode3 = createIterator(group->paths);
		ListIterator *nodePtr3 = &curNode3;
		Path *path;

		while (nodePtr3->current != NULL)
		{
			path = nodePtr3->current->data;

			/*
			//new path for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY
			Path *newPath = malloc(sizeof(Path));
			newPath->data = malloc(sizeof(char) * strlen(path->data) + 1);
			strcpy(newPath->data, path->data);

			List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			if (getLength(path->otherAttributes) > 0)
			{
				ListIterator curNode4 = createIterator(path->otherAttributes);
				ListIterator *nodePtr4 = &curNode4;
				Attribute *otherAttribute;

				while (nodePtr4->current != NULL)
				{
					otherAttribute = nodePtr4->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(otherAttributes, newOtherAttribute);

					nextElement(nodePtr4);
				}
			}
			newPath->otherAttributes = otherAttributes;
			insertBack(pathReturnList, newPath);
			*/

			insertBack(pathReturnList, path);
			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			getGroupPaths(pathReturnList, group->groups);
		}
		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}
}

List *getRects(SVGimage *img)
{
	if (img != NULL)
	{
		List *rectReturnList = initializeList(rectangleToString, deleteRectangle, compareRectangles);

		ListIterator curNode = createIterator(img->rectangles);
		ListIterator *nodePtr = &curNode;
		Rectangle *rect;

		while (nodePtr->current != NULL)
		{
			rect = nodePtr->current->data;

			/*
			//new rect for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY
			Rectangle *newRect = malloc(sizeof(Rectangle));

			newRect->x = rect->x;
			newRect->y = rect->y;
			newRect->width = rect->width;
			newRect->height = rect->height;
			strcpy(newRect->units, rect->units);

			List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			if (getLength(rect->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(rect->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttribute;

				while (nodePtr2->current != NULL)
				{
					otherAttribute = nodePtr2->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(otherAttributes, newOtherAttribute);

					nextElement(nodePtr2);
				}
			}

			newRect->otherAttributes = otherAttributes;
			insertBack(rectReturnList, newRect);
			*/
			insertBack(rectReturnList, rect);
			nextElement(nodePtr);
		}

		if (getLength(img->groups) > 0)
		{
			getGroupRects(rectReturnList, img->groups);
		}

		return rectReturnList;
	}

	return NULL;
}

void getGroupRects(List *rectReturnList, List *groupList)
{
	//group
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		ListIterator curNode3 = createIterator(group->rectangles);
		ListIterator *nodePtr3 = &curNode3;
		Rectangle *rect;

		while (nodePtr3->current != NULL)
		{
			rect = nodePtr3->current->data;

			/*
			//new rect for new list, VERY COOL BUT VERY HARD TO USE FUNCTIONIBILITY
			Rectangle *newRect = malloc(sizeof(Rectangle));

			newRect->x = rect->x;
			newRect->y = rect->y;
			newRect->width = rect->width;
			newRect->height = rect->height;
			strcpy(newRect->units, rect->units);

			List *otherAttributes = initializeList(attributeToString, deleteAttribute, compareAttributes);

			if (getLength(rect->otherAttributes) > 0)
			{
				ListIterator curNode4 = createIterator(rect->otherAttributes);
				ListIterator *nodePtr4 = &curNode4;
				Attribute *otherAttribute;

				while (nodePtr4->current != NULL)
				{
					otherAttribute = nodePtr4->current->data;

					Attribute *newOtherAttribute = malloc(sizeof(Attribute));
					newOtherAttribute->name = malloc(sizeof(char) * strlen(otherAttribute->name) + 1);
					strcpy(newOtherAttribute->name, otherAttribute->name);
					newOtherAttribute->value = malloc(sizeof(char) * strlen(otherAttribute->value) + 1);
					strcpy(newOtherAttribute->value, otherAttribute->value);
					insertBack(otherAttributes, newOtherAttribute);

					nextElement(nodePtr4);
				}
			}
			newRect->otherAttributes = otherAttributes;
			insertBack(rectReturnList, newRect);
			*/

			insertBack(rectReturnList, rect);

			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			getGroupRects(rectReturnList, group->groups);
		}
		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}
}

int numAttr(SVGimage *img) //SEG FAULT NEED TO FIX
{
	int counter = 0;
	ListIterator curNode;
	ListIterator *nodePtr = NULL;

	if (img != NULL)
	{
		if (getLength(img->otherAttributes) > 0)
		{
			counter = counter + getLength(img->otherAttributes);
		}

		curNode = createIterator(img->rectangles);
		nodePtr = &curNode;
		Rectangle *rect;

		if (nodePtr->current != NULL)
		{
			while (nodePtr->current != NULL)
			{
				rect = nodePtr->current->data;
				counter = counter + getLength(rect->otherAttributes);
				nextElement(nodePtr);
			}
		}

		curNode = createIterator(img->paths);
		nodePtr = &curNode;
		Path *path;

		if (nodePtr->current != NULL)
		{
			while (nodePtr->current != NULL)
			{
				path = nodePtr->current->data;
				counter = counter + getLength(path->otherAttributes);
				nextElement(nodePtr);
			}
		}

		curNode = createIterator(img->circles);
		nodePtr = &curNode;
		Circle *circle;

		if (nodePtr->current != NULL)
		{
			while (nodePtr->current != NULL)
			{
				circle = nodePtr->current->data;
				counter = counter + getLength(circle->otherAttributes);
				nextElement(nodePtr);
			}
		}

		if (getLength(img->groups) > 0)
		{
			counter = counter + groupNumAttr(img->groups);
		}
	}

	return counter;
}

int groupNumAttr(List *groupList)
{
	//group
	int counter = 0;
	ListIterator curNode = createIterator(groupList);
	ListIterator *nodePtr = &curNode;
	Group *group;
	//printf("num of rects in numRectsWithArea: %d\n", getLength(img->rectangles));

	while (nodePtr->current != NULL)
	{
		group = nodePtr->current->data;

		counter = counter + getLength(group->otherAttributes);

		ListIterator curNode2 = createIterator(group->rectangles);
		ListIterator *nodePtr2 = &curNode2;
		Rectangle *rect;

		while (nodePtr2->current != NULL)
		{
			rect = nodePtr2->current->data;
			counter = counter + getLength(rect->otherAttributes);
			nextElement(nodePtr2);
		}

		ListIterator curNode3 = createIterator(group->paths);
		ListIterator *nodePtr3 = &curNode3;
		Path *path;

		while (nodePtr3->current != NULL)
		{
			path = nodePtr3->current->data;
			counter = counter + getLength(path->otherAttributes);
			nextElement(nodePtr3);
		}

		ListIterator curNode4 = createIterator(group->circles);
		ListIterator *nodePtr4 = &curNode4;
		Circle *circle;

		while (nodePtr4->current != NULL)
		{
			circle = nodePtr4->current->data;
			counter = counter + getLength(circle->otherAttributes);
			nextElement(nodePtr4);
		}

		if (getLength(group->groups) > 0)
		{
			counter = counter + groupNumAttr(group->groups);
		}

		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr);
	}

	return counter;
}

int numRectsWithArea(SVGimage *img, float area) //WORKS
{
	int counter = 0;

	if (img == NULL)
	{
		return counter;
	}
	else
	{
		ListIterator curNode = createIterator(img->rectangles);
		ListIterator *nodePtr = &curNode;
		Rectangle *rect;

		//printf("num of rects in numRectsWithArea: %d\n", getLength(img->rectangles));

		while (nodePtr->current != NULL)
		{
			rect = nodePtr->current->data;

			if (ceil(rect->width * rect->height) == ceil(area))
			{
				counter++;
			}

			nextElement(nodePtr);
		}

		if (getLength(img->groups) > 0)
		{
			counter = counter + groupRectArea(img->groups, area);
		}

		return counter;
	}
}

int groupRectArea(List *groupList, int area)
{
	//group
	int counter = 0;
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;
	//printf("num of rects in numRectsWithArea: %d\n", getLength(img->rectangles));

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		ListIterator curNode3 = createIterator(group->rectangles);
		ListIterator *nodePtr3 = &curNode3;
		Rectangle *rect2;

		while (nodePtr3->current != NULL)
		{
			rect2 = nodePtr3->current->data;

			if (ceil(rect2->width * rect2->height) == ceil(area))
			{
				counter++;
			}
			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			counter = counter + groupRectArea(group->groups, area);
		}

		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}

	return counter;
}

int numCirclesWithArea(SVGimage *img, float area) //works
{
	int counter = 0;
	float pi = 3.141592;

	if (img == NULL)
	{
		return counter;
	}
	else
	{
		ListIterator curNode = createIterator(img->circles);
		ListIterator *nodePtr = &curNode;
		Circle *circle;

		while (nodePtr->current != NULL)
		{
			circle = nodePtr->current->data;
			if (ceil(pi * (circle->r * circle->r)) == ceil(area))
			{
				counter++;
				//printf("TEST TEST\n");
			}

			nextElement(nodePtr);
		}

		if (getLength(img->groups) > 0)
		{
			counter = counter + groupCircleArea(img->groups, area);
		}

		return counter;
	}
}

int groupCircleArea(List *groupList, float area)
{
	//group
	int counter = 0;
	float pi = 3.141592;
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		ListIterator curNode3 = createIterator(group->circles);
		ListIterator *nodePtr3 = &curNode3;
		Circle *circle;

		while (nodePtr3->current != NULL)
		{
			circle = nodePtr3->current->data;

			if (ceil(pi * (circle->r * circle->r)) == ceil(area))
			{
				counter++;
			}

			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			counter = counter + groupCircleArea(group->groups, area);
		}

		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}

	return counter;
}

int numPathsWithdata(SVGimage *img, char *data) //works?
{
	int counter = 0;

	if (img == NULL)
	{
		return counter;
	}
	else
	{
		ListIterator curNode = createIterator(img->paths);
		ListIterator *nodePtr = &curNode;
		Path *path;
		while (nodePtr->current != NULL)
		{
			path = nodePtr->current->data;

			if (strcmp(path->data, data) == 0)
			{
				counter++;
			}

			nextElement(nodePtr);
		}

		if (getLength(img->groups) > 0)
		{
			counter = counter + groupPathData(img->groups, data);
		}

		return counter;
	}
}

int groupPathData(List *groupList, char *data)
{
	//group
	int counter = 0;
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		ListIterator curNode3 = createIterator(group->paths);
		ListIterator *nodePtr3 = &curNode3;
		Path *path;

		while (nodePtr3->current != NULL)
		{
			path = nodePtr3->current->data;

			if (strcmp(path->data, data) == 0)
			{
				counter++;
			}

			nextElement(nodePtr3);
		}

		if (getLength(group->groups) > 0)
		{
			counter = counter + groupPathData(group->groups, data);
		}

		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}

	return counter;
}

int numGroupsWithLen(SVGimage *img, int len)
{
	int counter = 0;

	if (img == NULL)
	{
		return counter;
	}
	else
	{
		ListIterator curNode = createIterator(img->groups);
		ListIterator *nodePtr = &curNode;
		Group *group;
		//printf("TEST");

		while (nodePtr->current != NULL)
		{
			group = nodePtr->current->data;

			/*
			printf("rect: %d\n", getLength(group->rectangles));
			printf("path: %d\n", getLength(group->paths));
			printf("circle: %d\n", getLength(group->circles));
			printf("group: %d\n", getLength(group->groups));

			printf("total: %d\n\n", getLength(group->rectangles) + getLength(group->paths) + getLength(group->groups) + getLength(group->circles));
			*/

			if (getLength(group->rectangles) + getLength(group->paths) + getLength(group->groups) + getLength(group->circles) == len)
			{
				counter++;
			}

			nextElement(nodePtr);
		}

		if (getLength(group->groups) > 0)
		{
			counter = counter + groupLen(group->groups, len);
		}

		return counter;
	}
}

int groupLen(List *groupList, int len)
{
	//group
	int counter = 0;
	ListIterator curNode2 = createIterator(groupList);
	ListIterator *nodePtr2 = &curNode2;
	Group *group;

	while (nodePtr2->current != NULL)
	{
		group = nodePtr2->current->data;

		/*
		printf("rect: %d\n", getLength(group->rectangles));
		printf("path: %d\n", getLength(group->paths));
		printf("circle: %d\n", getLength(group->circles));
		printf("group: %d\n", getLength(group->groups));

		printf("total: %d\n\n", getLength(group->rectangles) + getLength(group->paths) + getLength(group->groups) + getLength(group->circles));
		*/
		if (getLength(group->rectangles) + getLength(group->paths) + getLength(group->groups) + getLength(group->circles) == len)
		{
			counter++;
		}

		if (getLength(group->groups) > 0)
		{
			counter = counter + groupLen(group->groups, len);
		}

		//groupRectArea(counter, group->rectangles, group->groups, area);
		nextElement(nodePtr2);
	}

	return counter;
}

SVGimage *createValidSVGimage(char *fileName, char *schemaFile)
{
	xmlDoc *file = NULL;
	xmlNode *root = NULL;
	SVGimage *storage = NULL;
	int ret = -1;

	//Create schema to check svg
	/*
	xmlSchemaPtr schema = NULL;
	xmlSchemaParserCtxtPtr ctxt;

	xmlLineNumbersDefault(1);
	ctxt = xmlSchemaNewParserCtxt(schemaFile);
	xmlSchemaSetParserErrors(ctxt, (xmlSchemaValidityErrorFunc)fprintf, (xmlSchemaValidityWarningFunc)fprintf, stderr);
	schema = xmlSchemaParse(ctxt);
	xmlSchemaFreeParserCtxt(ctxt);
	*/
	//xmlSchemaDump(stdout, schema); //To print schema dump

	file = xmlReadFile(fileName, NULL, 0);

	if (file == NULL)
	{
		printf("xml cannot be parsed\n");

		//free the resource
		/*
		if (schema != NULL)
		{
			xmlSchemaFree(schema);
			xmlSchemaCleanupTypes();
			xmlCleanupParser();
			xmlMemoryDump();
		}
		*/

		return NULL;
	}

	/*
	xmlSchemaValidCtxtPtr ctxt2;
	int ret;

	ctxt2 = xmlSchemaNewValidCtxt(schema);
	xmlSchemaSetValidErrors(ctxt2, (xmlSchemaValidityErrorFunc)fprintf, (xmlSchemaValidityWarningFunc)fprintf, stderr);
	ret = xmlSchemaValidateDoc(ctxt2, file);
	*/

	//runs validator to check file
	ret = svgValidator(schemaFile, file);

	if (ret == 0)
	{
		printf("%s validates\n", fileName);

		storage = malloc(sizeof(SVGimage));

		storage->namespace[0] = '\0';
		storage->title[0] = '\0';
		storage->description[0] = '\0';

		//since valid, start parsing
		List *rectList = initializeList(rectangleToString, deleteRectangle, compareRectangles);
		List *circleList = initializeList(circleToString, deleteCircle, compareCircles);
		List *pathList = initializeList(pathToString, deletePath, comparePaths);
		List *groupList = initializeList(groupToString, deleteGroup, compareGroups);
		List *otherAttributeList = initializeList(attributeToString, deleteAttribute, compareAttributes);

		root = xmlDocGetRootElement(file);

		print_element_names(root, storage, rectList, circleList, pathList, groupList, otherAttributeList);

		storage->rectangles = rectList;
		storage->circles = circleList;
		storage->paths = pathList;
		storage->groups = groupList;
		storage->otherAttributes = otherAttributeList;

		//xmlFreeDoc(file);
	}
	else if (ret > 0)
	{
		printf("%s fails to validate\n", fileName);
	}
	else
	{
		printf("%s validation generated an internal error\n", fileName);
	}

	/*
	xmlSchemaFreeValidCtxt(ctxt2);

	//free the resource
	if (schema != NULL)
	{
		xmlSchemaFree(schema);
		xmlSchemaCleanupTypes();
		xmlCleanupParser();
		xmlMemoryDump();
	}
	*/

	xmlFreeDoc(file);
	//xmlCleanupParser();

	return storage;
}

int svgValidator(char *schemaFile, xmlDoc *file)
{

	//Create schema to check svg
	xmlSchemaPtr schema = NULL;
	xmlSchemaParserCtxtPtr ctxt = NULL;
	xmlSchemaValidCtxtPtr ctxt2 = NULL;
	int ret = -1;

	xmlLineNumbersDefault(1);
	ctxt = xmlSchemaNewParserCtxt(schemaFile);
	xmlSchemaSetParserErrors(ctxt, (xmlSchemaValidityErrorFunc)fprintf, (xmlSchemaValidityWarningFunc)fprintf, stderr);
	schema = xmlSchemaParse(ctxt);
	xmlSchemaFreeParserCtxt(ctxt);
	//xmlSchemaDump(stdout, schema); //To print schema dump

	ctxt2 = xmlSchemaNewValidCtxt(schema);
	xmlSchemaSetValidErrors(ctxt2, (xmlSchemaValidityErrorFunc)fprintf, (xmlSchemaValidityWarningFunc)fprintf, stderr);
	ret = xmlSchemaValidateDoc(ctxt2, file);

	xmlSchemaFreeValidCtxt(ctxt2);

	//free the resource
	if (schema != NULL)
	{
		xmlSchemaFree(schema);
		xmlSchemaCleanupTypes();
		xmlCleanupParser();
		xmlMemoryDump();
	}

	return ret;
}

bool writeSVGimage(SVGimage *doc, char *fileName)
{
	if (doc != NULL)
	{
		xmlDocPtr file = NULL; /* document pointer */
		xmlNodePtr root_node = NULL;
		xmlNodePtr node = NULL; /* node pointers */
		char buffer[1024];
		FILE *fp = NULL;
		xmlNsPtr ns = NULL;
		LIBXML_TEST_VERSION;

		/* 
     * Creates a new document, a node and set it as a root node
     */
		file = xmlNewDoc(BAD_CAST NULL);
		root_node = xmlNewNode(NULL, BAD_CAST "svg");
		xmlDocSetRootElement(file, root_node);

		//name space
		ns = xmlNewNs(root_node, (xmlChar *)doc->namespace, NULL);
		if (ns != NULL)
		{
			xmlSetNs(root_node, ns);
		}

		if (getLength(doc->otherAttributes) > 0)
		{
			ListIterator curNode2 = createIterator(doc->otherAttributes);
			ListIterator *nodePtr2 = &curNode2;
			Attribute *otherAttributes;

			while (nodePtr2->current != NULL)
			{
				otherAttributes = nodePtr2->current->data;
				xmlNewProp(root_node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
				nextElement(nodePtr2);
			}
		}

		if (strlen(doc->title) > 0)
		{
			xmlNewChild(root_node, NULL, BAD_CAST "title", (xmlChar *)doc->title);
		}

		if (strlen(doc->description) > 0)
		{
			xmlNewChild(root_node, NULL, BAD_CAST "desc", (xmlChar *)doc->description);
		}

		/*
     * Creates a DTD declaration. Isn't mandatory. 
     */
		//xmlCreateIntSubset(file, BAD_CAST "root", NULL, BAD_CAST "tree2.dtd");

		/* 
     * xmlNewChild() creates a new node, which is "attached" as child node
     * of root_node node. 
     */

		//rectangles
		if (getLength(doc->rectangles) > 0)
		{
			ListIterator curNode = createIterator(doc->rectangles);
			ListIterator *nodePtr = &curNode;
			Rectangle *rect;

			while (nodePtr->current != NULL)
			{
				rect = nodePtr->current->data;
				node = xmlNewChild(root_node, NULL, BAD_CAST "rect", BAD_CAST NULL);
				if (strlen(rect->units) > 0)
				{
					sprintf(buffer, "%.2f", rect->x);
					strcat(buffer, rect->units);
					xmlNewProp(node, BAD_CAST "x", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", rect->y);
					strcat(buffer, rect->units);
					xmlNewProp(node, BAD_CAST "y", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", rect->width);
					strcat(buffer, rect->units);
					xmlNewProp(node, BAD_CAST "width", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", rect->height);
					strcat(buffer, rect->units);
					xmlNewProp(node, BAD_CAST "height", (xmlChar *)buffer);

					if (getLength(rect->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(rect->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttributes;

						while (nodePtr2->current != NULL)
						{
							otherAttributes = nodePtr2->current->data;
							xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
							nextElement(nodePtr2);
						}
					}
				}
				else
				{
					sprintf(buffer, "%.2f", rect->x);
					xmlNewProp(node, BAD_CAST "x", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", rect->y);
					xmlNewProp(node, BAD_CAST "y", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", rect->width);
					xmlNewProp(node, BAD_CAST "width", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", rect->height);
					xmlNewProp(node, BAD_CAST "height", (xmlChar *)buffer);

					if (getLength(rect->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(rect->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttributes;

						while (nodePtr2->current != NULL)
						{
							otherAttributes = nodePtr2->current->data;
							xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
							nextElement(nodePtr2);
						}
					}
				}

				nextElement(nodePtr);
			}
		}

		//circles
		if (getLength(doc->circles) > 0)
		{
			ListIterator curNode = createIterator(doc->circles);
			ListIterator *nodePtr = &curNode;
			Circle *circle;

			while (nodePtr->current != NULL)
			{
				circle = nodePtr->current->data;
				node = xmlNewChild(root_node, NULL, BAD_CAST "circle", BAD_CAST NULL);
				if (strlen(circle->units) > 0)
				{
					sprintf(buffer, "%.2f", circle->cx);
					strcat(buffer, circle->units);
					xmlNewProp(node, BAD_CAST "cx", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", circle->cy);
					strcat(buffer, circle->units);
					xmlNewProp(node, BAD_CAST "cy", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", circle->r);
					strcat(buffer, circle->units);
					xmlNewProp(node, BAD_CAST "r", (xmlChar *)buffer);

					if (getLength(circle->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(circle->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttributes;

						while (nodePtr2->current != NULL)
						{
							otherAttributes = nodePtr2->current->data;
							xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
							nextElement(nodePtr2);
						}
					}
				}
				else
				{
					sprintf(buffer, "%.2f", circle->cx);
					strcat(buffer, circle->units);
					xmlNewProp(node, BAD_CAST "cx", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", circle->cy);
					strcat(buffer, circle->units);
					xmlNewProp(node, BAD_CAST "cy", (xmlChar *)buffer);
					sprintf(buffer, "%.2f", circle->r);
					strcat(buffer, circle->units);
					xmlNewProp(node, BAD_CAST "r", (xmlChar *)buffer);

					if (getLength(circle->otherAttributes) > 0)
					{
						ListIterator curNode2 = createIterator(circle->otherAttributes);
						ListIterator *nodePtr2 = &curNode2;
						Attribute *otherAttributes;

						while (nodePtr2->current != NULL)
						{
							otherAttributes = nodePtr2->current->data;
							xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
							nextElement(nodePtr2);
						}
					}
				}

				nextElement(nodePtr);
			}
		}

		//paths
		if (getLength(doc->paths) > 0)
		{
			ListIterator curNode = createIterator(doc->paths);
			ListIterator *nodePtr = &curNode;
			Path *path;

			while (nodePtr->current != NULL)
			{
				path = nodePtr->current->data;
				node = xmlNewChild(root_node, NULL, BAD_CAST "path", BAD_CAST NULL);

				xmlNewProp(node, BAD_CAST "d", (xmlChar *)path->data);

				if (getLength(path->otherAttributes) > 0)
				{
					ListIterator curNode2 = createIterator(path->otherAttributes);
					ListIterator *nodePtr2 = &curNode2;
					Attribute *otherAttributes;

					while (nodePtr2->current != NULL)
					{
						otherAttributes = nodePtr2->current->data;
						xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
						nextElement(nodePtr2);
					}
				}

				nextElement(nodePtr);
			}
		}

		//groups
		if (getLength(doc->groups) > 0)
		{
			ListIterator curNode = createIterator(doc->groups);
			ListIterator *nodePtr = &curNode;
			Group *group;

			while (nodePtr->current != NULL)
			{
				group = nodePtr->current->data;
				node = xmlNewChild(root_node, NULL, BAD_CAST "g", BAD_CAST NULL);

				if (getLength(group->otherAttributes) > 0)
				{
					ListIterator curNode2 = createIterator(group->otherAttributes);
					ListIterator *nodePtr2 = &curNode2;
					Attribute *otherAttributes;

					while (nodePtr2->current != NULL)
					{
						otherAttributes = nodePtr2->current->data;
						xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
						nextElement(nodePtr2);
					}
				}

				buildGroup(group, node);

				nextElement(nodePtr);
			}
		}

		/* 
     * Dumping document to stdio or file
     */
		xmlSaveFormatFileEnc(fileName, file, "UTF-8", 1);
		//xmlSaveFormatFile(fileName, file, 1);

		/*free the document */
		xmlFreeDoc(file);

		/*
     *Free the global variables that may
     *have been allocated by the parser.
     */
		xmlCleanupParser();

		/*
     * this is to debug memory for regression tests
     */
		xmlMemoryDump();

		fp = fopen(fileName, "r");

		if (fp == NULL)
		{
			return false;
		}
		else
		{
			fclose(fp);
			return true;
		}
	}
	return false;
}

void buildGroup(Group *groupList, xmlNodePtr g_node)
{
	xmlNodePtr node = NULL;
	char buffer[1024];

	//rectangles
	if (getLength(groupList->rectangles) > 0)
	{
		ListIterator curNode = createIterator(groupList->rectangles);
		ListIterator *nodePtr = &curNode;
		Rectangle *rect;

		while (nodePtr->current != NULL)
		{
			rect = nodePtr->current->data;
			node = xmlNewChild(g_node, NULL, BAD_CAST "rect", BAD_CAST NULL);
			if (strlen(rect->units) > 0)
			{
				sprintf(buffer, "%.2f", rect->x);
				strcat(buffer, rect->units);
				xmlNewProp(node, BAD_CAST "x", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", rect->y);
				strcat(buffer, rect->units);
				xmlNewProp(node, BAD_CAST "y", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", rect->width);
				strcat(buffer, rect->units);
				xmlNewProp(node, BAD_CAST "width", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", rect->height);
				strcat(buffer, rect->units);
				xmlNewProp(node, BAD_CAST "height", (xmlChar *)buffer);

				if (getLength(rect->otherAttributes) > 0)
				{
					ListIterator curNode2 = createIterator(rect->otherAttributes);
					ListIterator *nodePtr2 = &curNode2;
					Attribute *otherAttributes;

					while (nodePtr2->current != NULL)
					{
						otherAttributes = nodePtr2->current->data;
						xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
						nextElement(nodePtr2);
					}
				}
			}
			else
			{
				sprintf(buffer, "%.2f", rect->x);
				xmlNewProp(node, BAD_CAST "x", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", rect->y);
				xmlNewProp(node, BAD_CAST "y", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", rect->width);
				xmlNewProp(node, BAD_CAST "width", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", rect->height);
				xmlNewProp(node, BAD_CAST "height", (xmlChar *)buffer);

				if (getLength(rect->otherAttributes) > 0)
				{
					ListIterator curNode2 = createIterator(rect->otherAttributes);
					ListIterator *nodePtr2 = &curNode2;
					Attribute *otherAttributes;

					while (nodePtr2->current != NULL)
					{
						otherAttributes = nodePtr2->current->data;
						xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
						nextElement(nodePtr2);
					}
				}
			}

			nextElement(nodePtr);
		}
	}

	//circles
	if (getLength(groupList->circles) > 0)
	{
		ListIterator curNode = createIterator(groupList->circles);
		ListIterator *nodePtr = &curNode;
		Circle *circle;

		while (nodePtr->current != NULL)
		{
			circle = nodePtr->current->data;
			node = xmlNewChild(g_node, NULL, BAD_CAST "circle", BAD_CAST NULL);
			if (strlen(circle->units) > 0)
			{
				sprintf(buffer, "%.2f", circle->cx);
				strcat(buffer, circle->units);
				xmlNewProp(node, BAD_CAST "cx", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", circle->cy);
				strcat(buffer, circle->units);
				xmlNewProp(node, BAD_CAST "cy", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", circle->r);
				strcat(buffer, circle->units);
				xmlNewProp(node, BAD_CAST "r", (xmlChar *)buffer);

				if (getLength(circle->otherAttributes) > 0)
				{
					ListIterator curNode2 = createIterator(circle->otherAttributes);
					ListIterator *nodePtr2 = &curNode2;
					Attribute *otherAttributes;

					while (nodePtr2->current != NULL)
					{
						otherAttributes = nodePtr2->current->data;
						xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
						nextElement(nodePtr2);
					}
				}
			}
			else
			{
				sprintf(buffer, "%.2f", circle->cx);
				strcat(buffer, circle->units);
				xmlNewProp(node, BAD_CAST "cx", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", circle->cy);
				strcat(buffer, circle->units);
				xmlNewProp(node, BAD_CAST "cy", (xmlChar *)buffer);
				sprintf(buffer, "%.2f", circle->r);
				strcat(buffer, circle->units);
				xmlNewProp(node, BAD_CAST "r", (xmlChar *)buffer);

				if (getLength(circle->otherAttributes) > 0)
				{
					ListIterator curNode2 = createIterator(circle->otherAttributes);
					ListIterator *nodePtr2 = &curNode2;
					Attribute *otherAttributes;

					while (nodePtr2->current != NULL)
					{
						otherAttributes = nodePtr2->current->data;
						xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
						nextElement(nodePtr2);
					}
				}
			}

			nextElement(nodePtr);
		}
	}

	//paths
	if (getLength(groupList->paths) > 0)
	{
		ListIterator curNode = createIterator(groupList->paths);
		ListIterator *nodePtr = &curNode;
		Path *path;

		while (nodePtr->current != NULL)
		{
			path = nodePtr->current->data;
			node = xmlNewChild(g_node, NULL, BAD_CAST "path", BAD_CAST NULL);

			xmlNewProp(node, BAD_CAST "d", (xmlChar *)path->data);

			if (getLength(path->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(path->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttributes;

				while (nodePtr2->current != NULL)
				{
					otherAttributes = nodePtr2->current->data;
					xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
					nextElement(nodePtr2);
				}
			}
			nextElement(nodePtr);
		}
	}

	//paths
	if (getLength(groupList->groups) > 0)
	{
		ListIterator curNode = createIterator(groupList->groups);
		ListIterator *nodePtr = &curNode;
		Group *group;

		while (nodePtr->current != NULL)
		{
			group = nodePtr->current->data;
			node = xmlNewChild(g_node, NULL, BAD_CAST "g", BAD_CAST NULL);

			if (getLength(group->otherAttributes) > 0)
			{
				ListIterator curNode2 = createIterator(group->otherAttributes);
				ListIterator *nodePtr2 = &curNode2;
				Attribute *otherAttributes;

				while (nodePtr2->current != NULL)
				{
					otherAttributes = nodePtr2->current->data;
					xmlNewProp(node, (xmlChar *)otherAttributes->name, (xmlChar *)otherAttributes->value);
					nextElement(nodePtr2);
				}
			}

			buildGroup(group, node);

			nextElement(nodePtr);
		}
	}
}

bool validateSVGimage(SVGimage *image, char *schemaFile)
{
	char *svgName = "_temp_outout_file_for_validateSVGimage_.svg";
	int result = -1;
	bool svgExists = false;
	xmlDoc *file = NULL;
	int errorCounter = 0;

	List *rectList = NULL;
	List *circleList = NULL;
	List *pathList = NULL;
	List *groupList = NULL;

	if (image != NULL)
	{
		rectList = getRects(image);
		circleList = getCircles(image);
		pathList = getPaths(image);
		groupList = getGroups(image);

		if (strlen(image->namespace) == 0)
		{
			errorCounter++;
			//return false;
		}

		if (image->otherAttributes != NULL)
		{

			if (getLength(image->otherAttributes) > 0)
			{
				ListIterator curAttrNode3 = createIterator(image->otherAttributes);
				ListIterator *nodeAttrPtr3 = &curAttrNode3;
				Attribute *otherAttributes;

				while (nodeAttrPtr3->current != NULL)
				{
					otherAttributes = nodeAttrPtr3->current->data;

					if (otherAttributes->name == NULL || otherAttributes->value == NULL)
					{
						errorCounter++;
						//return false;
					}
					nextElement(nodeAttrPtr3);
				}
			}
			else
			{
				errorCounter++;
				//return false;
			}
		}
		else
		{
			errorCounter++;
			//return false;
		}

		//check rects
		if (rectList != NULL)
		{
			if (getLength(rectList) > 0)
			{
				ListIterator curNode = createIterator(rectList);
				ListIterator *nodePtr = &curNode;
				Rectangle *rect;

				while (nodePtr->current != NULL)
				{
					rect = nodePtr->current->data;

					if ((rect->width < 0.0) || (rect->height < 0.0))
					{
						errorCounter++;
						//return false;
					}

					if (rect->otherAttributes != NULL)
					{
						if (getLength(rect->otherAttributes) > 0)
						{
							ListIterator curNode2 = createIterator(rect->otherAttributes);
							ListIterator *nodePtr2 = &curNode2;
							Attribute *otherAttributes;

							while (nodePtr2->current != NULL)
							{
								otherAttributes = nodePtr2->current->data;

								if (otherAttributes->name == NULL || otherAttributes->value == NULL)
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodePtr2);
							}
						}
					}
					else
					{
						errorCounter++;
						//return false;
					}
					nextElement(nodePtr);
				}
			}
		}
		else
		{
			errorCounter++;
			//return false;
		}

		//circles
		if (circleList != NULL)
		{
			if (getLength(circleList) > 0)
			{
				ListIterator curNode = createIterator(circleList);
				ListIterator *nodePtr = &curNode;
				Circle *circle;

				while (nodePtr->current != NULL)
				{
					circle = nodePtr->current->data;

					if (circle->r < 0.0)
					{
						errorCounter++;
						//return false;
					}

					if (circle->otherAttributes != NULL)
					{
						//FIX 3.6
						if (getLength(circle->otherAttributes) > 0)
						{
							ListIterator curNode2 = createIterator(circle->otherAttributes);
							ListIterator *nodePtr2 = &curNode2;
							Attribute *otherAttributes;

							while (nodePtr2->current != NULL)
							{
								otherAttributes = nodePtr2->current->data;

								if (otherAttributes->name == NULL || otherAttributes->value == NULL)
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodePtr2);
							}
						}
					}
					else
					{
						printf("TEST TEST\n");
						errorCounter++;
						//return false;
					}

					nextElement(nodePtr);
				}
			}
		}
		else
		{
			//printf("TEST TEST\n");
			errorCounter++;
			//return false;
		}

		//paths

		if (pathList != NULL)
		{
			if (getLength(pathList) > 0)
			{
				ListIterator curNode = createIterator(pathList);
				ListIterator *nodePtr = &curNode;
				Path *path;

				while (nodePtr->current != NULL)
				{
					path = nodePtr->current->data;

					if (path->data == NULL)
					{
						errorCounter++;
						//return false;
					}

					if (path->otherAttributes != NULL)
					{

						if (getLength(path->otherAttributes) > 0)
						{
							ListIterator curNode2 = createIterator(path->otherAttributes);
							ListIterator *nodePtr2 = &curNode2;
							Attribute *otherAttributes;

							while (nodePtr2->current != NULL)
							{
								otherAttributes = nodePtr2->current->data;

								if (otherAttributes->name == NULL || otherAttributes->value == NULL)
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodePtr2);
							}
						}
					}
					else
					{
						errorCounter++;
						//return false;
					}
					nextElement(nodePtr);
				}
			}
		}
		else
		{
			errorCounter++;
			//return false;
		}

		//groups
		if (groupList != NULL)
		{

			if (getLength(groupList) > 0)
			{
				ListIterator curNode = createIterator(groupList);
				ListIterator *nodePtr = &curNode;
				Group *group;

				while (nodePtr->current != NULL)
				{
					group = nodePtr->current->data;

					if (group->rectangles != NULL)
					{
						//check rects inside of groups
						if (getLength(group->rectangles) > 0)
						{
							ListIterator curRectNode = createIterator(group->rectangles);
							ListIterator *nodeRectPtr = &curRectNode;
							Rectangle *rect;

							while (nodeRectPtr->current != NULL)
							{
								rect = nodeRectPtr->current->data;

								if ((rect->width < 0.0) || (rect->height < 0.0))
								{
									errorCounter++;
									//return false;
								}

								if (rect->otherAttributes != NULL)
								{
									if (getLength(rect->otherAttributes) > 0)
									{
										ListIterator curNode2 = createIterator(rect->otherAttributes);
										ListIterator *nodePtr2 = &curNode2;
										Attribute *otherAttributes;

										while (nodePtr2->current != NULL)
										{
											otherAttributes = nodePtr2->current->data;

											if (otherAttributes->name == NULL || otherAttributes->value == NULL)
											{
												errorCounter++;
												//return false;
											}
											nextElement(nodePtr2);
										}
									}
								}
								else
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodeRectPtr);
							}
						}
					}
					else
					{
						errorCounter++;
						//return false;
					}

					//circles

					if (group->circles != NULL)
					{

						if (getLength(group->circles) > 0)
						{
							ListIterator curCircleNode = createIterator(group->circles);
							ListIterator *nodeCirclePtr = &curCircleNode;
							Circle *circle;

							while (nodeCirclePtr->current != NULL)
							{
								circle = nodeCirclePtr->current->data;

								if (circle->r < 0.0)
								{
									errorCounter++;
									//return false;
								}

								if (circle->otherAttributes != NULL)
								{

									if (getLength(circle->otherAttributes) > 0)
									{
										ListIterator curNode2 = createIterator(circle->otherAttributes);
										ListIterator *nodePtr2 = &curNode2;
										Attribute *otherAttributes;

										while (nodePtr2->current != NULL)
										{
											otherAttributes = nodePtr2->current->data;

											if (otherAttributes->name == NULL || otherAttributes->value == NULL)
											{
												errorCounter++;
												//return false;
											}
											nextElement(nodePtr2);
										}
									}
								}
								else
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodeCirclePtr);
							}
						}
					}
					else
					{
						errorCounter++;
						//return false;
					}

					//paths inside the group

					if (group->paths != NULL)
					{

						if (getLength(group->paths) > 0)
						{
							ListIterator curPathNode = createIterator(group->paths);
							ListIterator *nodePathPtr = &curPathNode;
							Path *path;

							while (nodePathPtr->current != NULL)
							{
								path = nodePathPtr->current->data;

								if (path->data == NULL)
								{
									errorCounter++;
									//return false;
								}

								if (path->otherAttributes != NULL)
								{
									if (getLength(path->otherAttributes) > 0)
									{
										ListIterator curNode2 = createIterator(path->otherAttributes);
										ListIterator *nodePtr2 = &curNode2;
										Attribute *otherAttributes;

										while (nodePtr2->current != NULL)
										{
											otherAttributes = nodePtr2->current->data;

											if (otherAttributes->name == NULL || otherAttributes->value == NULL)
											{
												errorCounter++;
												//return false;
											}
											nextElement(nodePtr2);
										}
									}
								}
								else
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodePathPtr);
							}
						}
					}
					else
					{
						errorCounter++;
						//return false;
					}

					//other attr
					if (group->otherAttributes != NULL)
					{

						if (getLength(group->otherAttributes) > 0)
						{
							ListIterator curAttrNode2 = createIterator(group->otherAttributes);
							ListIterator *nodeAttrPtr2 = &curAttrNode2;
							Attribute *otherAttributes;

							while (nodeAttrPtr2->current != NULL)
							{
								otherAttributes = nodeAttrPtr2->current->data;

								if (otherAttributes->name == NULL || otherAttributes->value == NULL)
								{
									errorCounter++;
									//return false;
								}
								nextElement(nodeAttrPtr2);
							}
						}
					}
					else
					{
						errorCounter++;
						//return false;
					}
					nextElement(nodePtr);
				}
			}
		}
		else
		{
			errorCounter++;
			//return false;
		}
		//printf("%d\n", errorCounter);

		setListToEmpty(rectList);
		setListToEmpty(circleList);
		setListToEmpty(pathList);
		setListToEmpty(groupList);
		freeList(rectList);
		freeList(circleList);
		freeList(pathList);
		freeList(groupList);

		//Might be causing 3.6 crash

		if (errorCounter > 0)
		{
			return false;
		}
		else
		{
			svgExists = writeSVGimage(image, svgName);

			if (svgExists == true)
			{
				file = xmlReadFile(svgName, NULL, 0);

				if (file == NULL)
				{
					printf("xml cannot be parsed\n");

					xmlFreeDoc(file);
					xmlCleanupParser();
					return false;
				}
				result = svgValidator(schemaFile, file);

				xmlFreeDoc(file);
				xmlCleanupParser();

				if (result == 0)
				{
					return true;
				}
				else if (result > 0)
				{
					printf("%s fails to validate using %s\n", svgName, schemaFile);
					return false;
				}
				else
				{
					printf("%s validation generated an internal error\n", svgName);
					return false;
				}
			}
			else
			{
				return false;
			}
			//return true;
		}
	}
	else
	{
		return false;
	}
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

void setAttribute(SVGimage *image, elementType elemType, int elemIndex, Attribute *newAttribute)
{
	int naturalNum = elemIndex + 1;
	int indexCounter = 0;

	if (image != NULL)
	{
		if (elemType >= 0 && elemType <= 4)
		{
			if (newAttribute != NULL)
			{
				if (newAttribute->name != NULL && newAttribute->value != NULL)
				{
					//printf("TEST TEST\n");
					if (elemType == SVG_IMAGE)
					{
						//SVG_IMAGE

						ListIterator curNode = createIterator(image->otherAttributes);
						ListIterator *nodePtr = &curNode;
						Attribute *otherAttributes;

						while (nodePtr->current != NULL)
						{
							otherAttributes = nodePtr->current->data;

							if (strcmp(otherAttributes->name, newAttribute->name) == 0)
							{
								//free(otherAttributes->value);
								//otherAttributes->value = malloc(sizeof(char) * strlen(newAttribute->value) + 1);
								otherAttributes->value = realloc(otherAttributes->value, sizeof(char) * strlen(newAttribute->value) + 1);
								strcpy(otherAttributes->value, newAttribute->value);

								free(newAttribute->name);
								free(newAttribute->value);
								free(newAttribute);
								return;
							}
							nextElement(nodePtr);
						}

						insertBack(image->otherAttributes, newAttribute);

						return;
					}
					else if (elemType == CIRC && elemIndex >= 0)
					{
						//CIRC
						//This might not be needed

						ListIterator curNode = createIterator(image->circles);
						ListIterator *nodePtr = &curNode;
						Circle *circle;

						while (nodePtr->current != NULL)
						{
							circle = nodePtr->current->data;

							indexCounter++;

							if (indexCounter == naturalNum)
							{
								if (strcmp(newAttribute->name, "cx") == 0)
								{
									circle->cx = atof(newAttribute->value);
									return;
								}
								else if (strcmp(newAttribute->name, "cy") == 0)
								{
									circle->cy = atof(newAttribute->value);
									return;
								}
								else if (strcmp(newAttribute->name, "r") == 0)
								{
									circle->r = atof(newAttribute->value);
									return;
								}
								else
								{
									ListIterator curAttrNode = createIterator(circle->otherAttributes);
									ListIterator *nodeAttrPtr = &curAttrNode;
									Attribute *otherAttributes;

									while (nodeAttrPtr->current != NULL)
									{

										otherAttributes = nodeAttrPtr->current->data;

										if (strcmp(otherAttributes->name, newAttribute->name) == 0)
										{
											//free(otherAttributes->value);
											//otherAttributes->value = malloc(sizeof(char) * strlen(newAttribute->value) + 1);
											otherAttributes->value = realloc(otherAttributes->value, sizeof(char) * strlen(newAttribute->value) + 1);
											strcpy(otherAttributes->value, newAttribute->value);

											free(newAttribute->name);
											free(newAttribute->value);
											free(newAttribute);
											return;
										}
										nextElement(nodeAttrPtr);
									}
									insertBack(image->otherAttributes, newAttribute);
									return;
								}
							}
							nextElement(nodePtr);
						}
					}
					else if (elemType == RECT && elemIndex >= 0)
					{
						//RECT

						//This might not be needed

						ListIterator curNode = createIterator(image->rectangles);
						ListIterator *nodePtr = &curNode;
						Rectangle *rect;

						while (nodePtr->current != NULL)
						{
							rect = nodePtr->current->data;

							indexCounter++;
							if (indexCounter == naturalNum)
							{
								if (strcmp(newAttribute->name, "x") == 0)
								{
									rect->x = atof(newAttribute->value);
									return;
								}
								else if (strcmp(newAttribute->name, "y") == 0)
								{
									rect->y = atof(newAttribute->value);
									return;
								}
								else if (strcmp(newAttribute->name, "width") == 0)
								{
									rect->width = atof(newAttribute->value);
									return;
								}
								else if (strcmp(newAttribute->name, "height") == 0)
								{
									rect->height = atof(newAttribute->value);
									return;
								}
								else
								{

									ListIterator curAttrNode = createIterator(rect->otherAttributes);
									ListIterator *nodeAttrPtr = &curAttrNode;
									Attribute *otherAttributes;

									while (nodeAttrPtr->current != NULL)
									{
										//FIX HERE FOR 5.3
										otherAttributes = nodeAttrPtr->current->data;

										if (strcmp(otherAttributes->name, newAttribute->name) == 0)
										{
											//free(otherAttributes->value);
											//otherAttributes->value = malloc(sizeof(char) * strlen(newAttribute->value) + 1);
											otherAttributes->value = realloc(otherAttributes->value, sizeof(char) * strlen(newAttribute->value) + 1);
											strcpy(otherAttributes->value, newAttribute->value);

											free(newAttribute->name);
											free(newAttribute->value);
											free(newAttribute);
											return;
										}

										nextElement(nodeAttrPtr);
									}

									insertBack(rect->otherAttributes, newAttribute);
									return;
								}
							}
							nextElement(nodePtr);
						}
					}
					else if (elemType == PATH && elemIndex >= 0)
					{
						//PATH
						//This might not be needed

						ListIterator curNode = createIterator(image->paths);
						ListIterator *nodePtr = &curNode;
						Path *path;

						while (nodePtr->current != NULL)
						{
							path = nodePtr->current->data;

							indexCounter++;

							if (indexCounter == naturalNum)
							{
								if (strcmp(newAttribute->name, "d") == 0)
								{
									free(path->data);
									path->data = malloc(sizeof(char) * strlen(newAttribute->value) + 1);
									strcpy(path->data, newAttribute->value);
									return;
								}
								else
								{

									ListIterator curAttrNode = createIterator(path->otherAttributes);
									ListIterator *nodeAttrPtr = &curAttrNode;
									Attribute *otherAttributes;

									while (nodeAttrPtr->current != NULL)
									{

										otherAttributes = nodeAttrPtr->current->data;

										if (strcmp(otherAttributes->name, newAttribute->name) == 0)
										{

											otherAttributes->value = realloc(otherAttributes->value, sizeof(char) * strlen(newAttribute->value) + 1);

											strcpy(otherAttributes->value, newAttribute->value);

											free(newAttribute->name);
											free(newAttribute->value);
											free(newAttribute);
											return;
										}
										nextElement(nodeAttrPtr);
									}

									insertBack(path->otherAttributes, newAttribute);

									return;
								}
							}
							nextElement(nodePtr);
						}
					}
					else if (elemType == GROUP && elemIndex >= 0)
					{
						//GROUP

						//this if statment might not be needed

						ListIterator curNode = createIterator(image->groups);
						ListIterator *nodePtr = &curNode;
						Group *group;

						while (nodePtr->current != NULL)
						{
							group = nodePtr->current->data;

							indexCounter++;

							if (indexCounter == naturalNum)
							{

								ListIterator curAttrNode = createIterator(group->otherAttributes);
								ListIterator *nodeAttrPtr = &curAttrNode;
								Attribute *otherAttributes;

								while (nodeAttrPtr->current != NULL)
								{
									otherAttributes = nodeAttrPtr->current->data;

									if (strcmp(otherAttributes->name, newAttribute->name) == 0)
									{
										free(otherAttributes->value);
										otherAttributes->value = malloc(sizeof(char) * strlen(newAttribute->value) + 1);
										strcpy(otherAttributes->value, newAttribute->value);

										free(newAttribute->name);
										free(newAttribute->value);
										free(newAttribute);
										return;
									}
									nextElement(nodeAttrPtr);
								}

								insertBack(group->otherAttributes, newAttribute);

								return;
							}
							nextElement(nodePtr);
						}
					}
				}
			}
		}
	}
	printf("Invalid params.\n");
}

void addComponent(SVGimage *image, elementType elemType, void *newComponent)
{
	if ((image != NULL) && (newComponent != NULL) && (elemType >= 1) && (elemType <= 3))
	{
		if (elemType == CIRC)
		{
			Circle *circle = newComponent;
			insertBack(image->circles, circle);
		}
		else if (elemType == RECT)
		{
			Rectangle *rect = newComponent;
			insertBack(image->rectangles, rect);
		}
		else if (elemType == PATH)
		{
			Path *path = newComponent;
			insertBack(image->paths, path);
		}
	}
}

char *attrToJSON(const Attribute *a)
{
	char *str = NULL;

	if (a != NULL)
	{
		if ((a->name != NULL) && (a->value != NULL))
		{
			//{"name":"attrName","value":"attrVal"}

			str = malloc(sizeof(char) * 9 + 1);
			strcpy(str, "{\"name\":\"");
			str = realloc(str, sizeof(char) * (strlen(str) + strlen(a->name)) + 1);
			strcat(str, a->name);

			str = realloc(str, sizeof(char) * (strlen(str) + 11) + 1);
			strcat(str, "\",\"value\":\"");

			str = realloc(str, sizeof(char) * (strlen(str) + strlen(a->value)) + 1);
			strcat(str, a->value);

			str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
			strcat(str, "\"}");
		}
		else
		{
			str = malloc(sizeof(char) * 2 + 1);
			strcpy(str, "{}");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "{}");
	}

	return str;
}

char *circleToJSON(const Circle *c)
{
	char *str = NULL;
	char buffer[1024];

	if (c != NULL)
	{
		//{"cx":xVal,"cy":yVal,"r":rVal,"numAttr":attVal,"units":"unitStr"}

		str = malloc(sizeof(char) * 6 + 1);
		;
		strcpy(str, "{\"cx\":");

		sprintf(buffer, "%.2f", c->cx);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 6) + 1);
		strcat(str, ",\"cy\":");

		sprintf(buffer, "%.2f", c->cy);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 5) + 1);
		strcat(str, ",\"r\":");

		sprintf(buffer, "%.2f", c->r);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 11) + 1);
		strcat(str, ",\"numAttr\":");

		sprintf(buffer, "%.0f", (float)getLength(c->otherAttributes));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 9) + 1);
		strcat(str, ",\"units\":\"");

		if (strlen(c->units) > 0)
		{
			str = realloc(str, sizeof(char) * (strlen(str) + strlen(c->units)) + 1);
			strcat(str, c->units);
		}

		str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
		strcat(str, "\"}");
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "{}");
	}

	return str;
}

char *rectToJSON(const Rectangle *r)
{
	char *str = NULL;
	char buffer[1024];

	if (r != NULL)
	{
		//{"x":xVal,"y":yVal,"w":wVal,"h":hVal,"numAttr":attVal,"units":"unitStr"}

		str = malloc(sizeof(char) * 5 + 1);
		;
		strcpy(str, "{\"x\":");

		sprintf(buffer, "%.2f", r->x);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 5) + 1);
		strcat(str, ",\"y\":");

		sprintf(buffer, "%.2f", r->y);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 5) + 1);
		strcat(str, ",\"w\":");

		sprintf(buffer, "%.2f", r->width);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 5) + 1);
		strcat(str, ",\"h\":");

		sprintf(buffer, "%.2f", r->height);
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 11) + 1);
		strcat(str, ",\"numAttr\":");

		sprintf(buffer, "%.0f", (float)getLength(r->otherAttributes));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 9) + 1);
		strcat(str, ",\"units\":\"");

		if (strlen(r->units) > 0)
		{
			str = realloc(str, sizeof(char) * (strlen(str) + strlen(r->units)) + 1);
			strcat(str, r->units);
		}

		str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
		strcat(str, "\"}");
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "{}");
	}

	return str;
}

char *pathToJSON(const Path *p)
{
	char *str = NULL;
	char buffer[1024];

	if (p != NULL)
	{
		if (p->data != NULL)
		{
			//{"d":"dVal","numAttr":attVal}

			str = malloc(sizeof(char) * 6 + 1);
			strcpy(str, "{\"d\":\"");

			if (strlen(p->data) > 64)
			{
				strncpy(buffer, p->data, 64);
				buffer[64] = '\0';
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
				strcat(str, buffer);
			}
			else
			{
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(p->data)) + 1);
				strcat(str, p->data);
			}

			str = realloc(str, sizeof(char) * (strlen(str) + 12) + 1);
			strcat(str, "\",\"numAttr\":");

			sprintf(buffer, "%.0f", (float)getLength(p->otherAttributes));
			str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
			strcat(str, buffer);

			str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
			strcat(str, "}");
		}
		else
		{
			str = malloc(sizeof(char) * 2 + 1);
			strcpy(str, "{}");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "{}");
	}
	return str;
}

char *groupToJSON(const Group *g)
{
	char *str = NULL;
	char buffer[1024];

	if (g != NULL)
	{
		//{"children":cVal,"numAttr":attVal}

		str = malloc(sizeof(char) * 12 + 1);
		strcpy(str, "{\"children\":");

		sprintf(buffer, "%.0f", (float)getLength(g->rectangles) + (float)getLength(g->circles) + (float)getLength(g->paths) + (float)getLength(g->groups));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 11) + 1);
		strcat(str, ",\"numAttr\":");

		sprintf(buffer, "%.0f", (float)getLength(g->otherAttributes));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
		strcat(str, "}");
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "{}");
	}
	return str;
}

char *SVGtoJSON(const SVGimage *imge)
{
	char *str = NULL;
	char buffer[1024];

	if (imge != NULL)
	{
		List *rect = getRects((SVGimage *)imge);
		List *circle = getCircles((SVGimage *)imge);
		List *path = getPaths((SVGimage *)imge);
		List *group = getGroups((SVGimage *)imge);
		//{"numRect":numR,"numCirc":numC,"numPaths":numP,"numGroups":numG}

		str = malloc(sizeof(char) * 11 + 1);
		strcpy(str, "{\"numRect\":");

		sprintf(buffer, "%.0f", (float)getLength(rect));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 11) + 1);
		strcat(str, ",\"numCirc\":");

		sprintf(buffer, "%.0f", (float)getLength(circle));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 12) + 1);
		strcat(str, ",\"numPaths\":");

		sprintf(buffer, "%.0f", (float)getLength(path));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 13) + 1);
		strcat(str, ",\"numGroups\":");

		sprintf(buffer, "%.0f", (float)getLength(group));
		str = realloc(str, sizeof(char) * (strlen(str) + strlen(buffer)) + 1);
		strcat(str, buffer);

		str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
		strcat(str, "}");

		setListToEmpty(rect);
		setListToEmpty(circle);
		setListToEmpty(path);
		setListToEmpty(group);
		freeList(rect);
		freeList(circle);
		freeList(path);
		freeList(group);
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "{}");
	}
	return str;
}

char *attrListToJSON(const List *list)
{
	List *attrList = (List *)list;
	char *str = NULL;
	char *attrStr = NULL;

	if (list != NULL)
	{
		//[{"name":"fill","value":"none"},{"name":"stroke","value":"blue"},{"name":"stroke-width","value":"1"}]

		if (getLength(attrList) > 0) //empty list check?
		{
			str = malloc(sizeof(char) * 1 + 1);
			strcpy(str, "[");

			ListIterator curAttrNode = createIterator(attrList);
			ListIterator *nodeAttrPtr = &curAttrNode;
			Attribute *otherAttributes;

			while (nodeAttrPtr->current != NULL)
			{
				otherAttributes = nodeAttrPtr->current->data;

				attrStr = attrToJSON(otherAttributes);
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(attrStr)) + 1);
				strcat(str, attrStr);
				free(attrStr);
				if (nodeAttrPtr->current->next != NULL)
				{
					str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
					strcat(str, ",");
				}

				nextElement(nodeAttrPtr);
			}

			str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
			strcat(str, "]");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "[]");
	}
	return str;
}

char *circListToJSON(const List *list)
{
	List *circleList = (List *)list;
	char *str = NULL;
	char *circStr = NULL;

	if (list != NULL)
	{
		//[{"cx":32,"cy":32,"r":30,"numAttr":1,"units":""},{"cx":32,"cy":32,"r":30,"numAttr":0,"units":"cm"}]

		if (getLength(circleList) > 0) //empty list check?
		{
			str = malloc(sizeof(char) * 1 + 1);
			strcpy(str, "[");

			ListIterator curCircNode = createIterator(circleList);
			ListIterator *nodeCircPtr = &curCircNode;
			Circle *circle;

			while (nodeCircPtr->current != NULL)
			{
				circle = nodeCircPtr->current->data;

				circStr = circleToJSON(circle);
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(circStr)) + 1);
				strcat(str, circStr);
				free(circStr);
				if (nodeCircPtr->current->next != NULL)
				{
					str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
					strcat(str, ",");
				}

				nextElement(nodeCircPtr);
			}

			str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
			strcat(str, "]");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "[]");
	}
	return str;
}
char *rectListToJSON(const List *list)
{
	List *rectList = (List *)list;
	char *str = NULL;
	char *rectStr = NULL;

	if (list != NULL)
	{
		//[{"x":1,"y":2,"w":19,"h":15,"numAttr":3,"units":"cm"},{"x":0,"y":0,"w":2,"h":2,"numAttr":0,"units":""}]

		if (getLength(rectList) > 0) //empty list check?
		{
			str = malloc(sizeof(char) * 1 + 1);
			strcpy(str, "[");

			ListIterator curRectNode = createIterator(rectList);
			ListIterator *nodeRectPtr = &curRectNode;
			Rectangle *rect;

			while (nodeRectPtr->current != NULL)
			{
				rect = nodeRectPtr->current->data;

				rectStr = rectToJSON(rect);
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(rectStr)) + 1);
				strcat(str, rectStr);
				free(rectStr);
				if (nodeRectPtr->current->next != NULL)
				{
					str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
					strcat(str, ",");
				}

				nextElement(nodeRectPtr);
			}

			str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
			strcat(str, "]");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "[]");
	}
	return str;
}
char *pathListToJSON(const List *list)
{
	List *pathList = (List *)list;
	char *str = NULL;
	char *pathStr = NULL;

	if (list != NULL)
	{
		//[{"d":"m47 36c-15 0-15 0-29.9 0-2.1 0-2.1 4-.1 4","numAttr":0},{"d":"m47 36c-15 0-15 0-29.9 0-2.1 0-2.1 4-.1 4 10.4 0 19.6 0 30 0 2 0","numAttr":1}]

		if (getLength(pathList) > 0) //empty list check?
		{
			str = malloc(sizeof(char) * 1 + 1);
			strcpy(str, "[");

			ListIterator curPathNode = createIterator(pathList);
			ListIterator *nodePathPtr = &curPathNode;
			Path *path;

			while (nodePathPtr->current != NULL)
			{
				path = nodePathPtr->current->data;

				pathStr = pathToJSON(path);
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(pathStr)) + 1);
				strcat(str, pathStr);
				free(pathStr);
				if (nodePathPtr->current->next != NULL)
				{
					str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
					strcat(str, ",");
				}

				nextElement(nodePathPtr);
			}

			str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
			strcat(str, "]");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "[]");
	}
	return str;
}
char *groupListToJSON(const List *list)
{
	List *groupList = (List *)list;
	char *str = NULL;
	char *groupStr = NULL;

	if (list != NULL)
	{
		//[{"children":2,"numAttr":1},{"children":3,"numAttr":1},{"children":2,"numAttr":1}]

		if (getLength(groupList) > 0) //empty list check?
		{
			str = malloc(sizeof(char) * 1 + 1);
			strcpy(str, "[");

			ListIterator curGroupNode = createIterator(groupList);
			ListIterator *nodeGroupPtr = &curGroupNode;
			Group *group;

			while (nodeGroupPtr->current != NULL)
			{
				group = nodeGroupPtr->current->data;

				groupStr = groupToJSON(group);
				str = realloc(str, sizeof(char) * (strlen(str) + strlen(groupStr)) + 1);
				strcat(str, groupStr);
				free(groupStr);
				if (nodeGroupPtr->current->next != NULL)
				{
					str = realloc(str, sizeof(char) * (strlen(str) + 2) + 1);
					strcat(str, ",");
				}

				nextElement(nodeGroupPtr);
			}

			str = realloc(str, sizeof(char) * (strlen(str) + 1) + 1);
			strcat(str, "]");
		}
	}
	else
	{
		str = malloc(sizeof(char) * 2 + 1);
		strcpy(str, "[]");
	}
	return str;
}

//For uploading to server
char *validSVGToJSON(char* fileName, char *schemaFile)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		str = SVGtoJSON(valid);
	}
	return str;
}


char* SVGcircListToJSON(char* fileName, char *schemaFile)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		List *list = getCircles(valid);
		str = circListToJSON(list);
	}
	return str;
}

char* SVGrectListToJSON(char* fileName, char *schemaFile)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		List *list = getRects(valid);
		str = rectListToJSON(list);
	}
	return str;
}

char* SVGpathListToJSON(char* fileName, char *schemaFile)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		List *list = getPaths(valid);
		str = pathListToJSON(list);
	}
	return str;
}

char* SVGgroupListToJSON(char* fileName, char *schemaFile)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		List *list = getGroups(valid);
		str = groupListToJSON(list);
	}
	return str;
}

char* titleAndDesc(char* fileName, char *schemaFile)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		for(int i = 0; i < strlen(valid->title); i++)
		{
			if(valid->title[i] == '\n')
			{
				valid->title[i] = ' ';
			}
		}

		for(int i = 0; i < strlen(valid->description); i++)
		{
			if(valid->description[i] == '\n')
			{
				valid->description[i] = ' ';
			}
		}

		str = malloc((sizeof(char) + 13) + 1);
		strcpy(str, "{\"svgTitle\":\"");

		if(strlen(valid->title) > 0)
		{
			str = realloc(str, (sizeof(char) * strlen(str) + strlen(valid->title)) + 1);
			strcat(str, valid->title);
		}
		str = realloc(str, (sizeof(char) * strlen(str) + 13) + 1);
		strcat(str, "\",\"svgDesc\":\"");
		if(strlen(valid->description) > 0)
		{
			str = realloc(str, (sizeof(char) * strlen(str) + strlen(valid->description)) + 1);
			strcat(str, valid->description);
		}

		str = realloc(str, (sizeof(char) * strlen(str) + 2) + 1);
		strcat(str, "\"}");

		/*
		if(strlen(valid->title) > 0 && strlen(valid->description) > 0)
		{
			str = malloc((sizeof(char) + 1) + 1);
			strcpy(str,"{");

			str = realloc(str, (sizeof(char) * strlen(str) + 11) + 1);
			strcat(str, "\"svgTitle\":");

			str = realloc(str, (sizeof(char) * strlen(str) + strlen(valid->title)) + 1);
			strcat(str, valid->title);

			str = realloc(str, (sizeof(char) * strlen(str) + 11) + 1);
			strcat(str, ",\"svgDesc\":");

			str = realloc(str, (sizeof(char) * strlen(str) + strlen(valid->description)) + 1);
			strcat(str, valid->description);

			str = realloc(str, (sizeof(char) * strlen(str) + 1) + 1);
			strcat(str, "}");
		}
		else if(strlen(valid->title) > 0 && strlen(valid->description) == 0)
		{
			str = malloc((sizeof(char) + 1) + 1);
			strcpy(str,"{");

			str = realloc(str, (sizeof(char) * strlen(str) + 11) + 1);
			strcat(str, "\"svgTitle\":");

			str = realloc(str, (sizeof(char) * strlen(str) + strlen(valid->title)) + 1);
			strcat(str, valid->title);
			
			str = realloc(str, (sizeof(char) * strlen(str) + 1) + 1);
			strcat(str, "}");
		}
		else if(strlen(valid->title) == 0 && strlen(valid->description) > 0)
		{
			str = malloc((sizeof(char) + 1) + 1);
			strcpy(str,"{");

			str = realloc(str, (sizeof(char) * strlen(str) + 10) + 1);
			strcat(str, "\"svgDesc\":");

			str = realloc(str, (sizeof(char) * strlen(str) + strlen(valid->description)) + 1);
			strcat(str, valid->description);

			str = realloc(str, (sizeof(char) * strlen(str) + 1) + 1);
			strcat(str, "}");
		}
		*/
	}
	return str;
}

char* showAttr(char* fileName, char *schemaFile, int index, char *type)
{
	char *str = NULL;
	SVGimage *valid = NULL;
	int counter = 0;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		if(strcmp(type, "rect") == 0)
		{
			List *list = getRects(valid);
			ListIterator curNode = createIterator(list);
			ListIterator *nodePtr = &curNode;
			Rectangle *rect;

			while (nodePtr->current != NULL)
			{
				rect = nodePtr->current->data;
				if(counter == index)
				{
					str = attrListToJSON(rect->otherAttributes);
				}
				counter++;
				nextElement(nodePtr);
			}
		}
		else if(strcmp(type, "circle") == 0)
		{
			List *list = getCircles(valid);
			ListIterator curNode = createIterator(list);
			ListIterator *nodePtr = &curNode;
			Circle *circle;

			while (nodePtr->current != NULL)
			{
				circle = nodePtr->current->data;
				if(counter == index)
				{
					str = attrListToJSON(circle->otherAttributes);
				}
				counter++;
				nextElement(nodePtr);
			}
		}
		else if(strcmp(type, "path") == 0)
		{
			List *list = getPaths(valid);
			ListIterator curNode = createIterator(list);
			ListIterator *nodePtr = &curNode;
			Path *path;

			while (nodePtr->current != NULL)
			{
				path = nodePtr->current->data;
				if(counter == index)
				{
					str = attrListToJSON(path->otherAttributes);
				}
				counter++;
				nextElement(nodePtr);
			}
		}		
		else if(strcmp(type, "group") == 0)
		{
			List *list = getGroups(valid);
			ListIterator curNode = createIterator(list);
			ListIterator *nodePtr = &curNode;
			Group *group;

			while (nodePtr->current != NULL)
			{
				group = nodePtr->current->data;
				if(counter == index)
				{
					str = attrListToJSON(group->otherAttributes);
				}
				counter++;
				nextElement(nodePtr);
			}
		}
	}
	return str;
}

void editAttr(char* fileName, char *schemaFile, int index, char *type, char *name, char *value)
{
	SVGimage *valid = NULL;
	valid = createValidSVGimage(fileName, schemaFile);
	if(valid != NULL)
	{
		Attribute *new = malloc(sizeof(Attribute));
		new->name = malloc(sizeof(char)* strlen(name) + 1);
		strcpy(new->name, name);
		new->value = malloc(sizeof(char)* strlen(value) + 1);
		strcpy(new->value, value);

		//CIRC, RECT, PATH, GROUP
		if(strcmp(type, "rect") == 0)
		{
			setAttribute(valid, RECT, index, new);
		}
		else if(strcmp(type, "circle") == 0)
		{
			setAttribute(valid, CIRC, index, new);

		}
		else if(strcmp(type, "path") == 0)
		{
			setAttribute(valid, PATH, index, new);

		}
		else if(strcmp(type, "group") == 0)
		{
			setAttribute(valid, GROUP, index, new);

		}
		writeSVGimage(valid, fileName);
	}
}