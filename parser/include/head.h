#ifndef HEAD_H
#define HEAD_H

#include "SVGParser.h"
#include <ctype.h>
#include <math.h>


static void findNamespace(xmlNode *cur_node, char array[256]);
static void otherAttributeHelper(xmlNode *cur_node, Attribute *otherAttribute, List *otherAttributeList);
static void pathHelper(xmlNode *cur_node, Path *path, List *otherAttributeList);
static void circleHelper(xmlNode *cur_node, Circle *circle, List *otherAttributeList);
static void rectHelper(xmlNode *cur_node, Rectangle *rect, List *otherAttributeList);

static void groupHelper(xmlNode *a_node, SVGimage *storage, Group *group /*, List *otherAttributeList */);

static void print_element_names(xmlNode *a_node, SVGimage *storage, List *rectList, List *circleList, List *pathList, List *groupList, List *otherAttributeList);
static void helper2(xmlNode *cur_node, char array[256]);


int groupRectArea(List *groupList, int area);
int groupCircleArea(List *groupList, float area);
int groupPathData(List *groupList, char *data);
int groupLen(List *groupList, int len);
int groupNumAttr(List *groupList);

void getGroupCircles(List *circleReturnList, List *groupList);
void getGroupRects(List *rectReturnList, List *groupList);
void getGroupPaths(List *pathReturnList, List *groupList);
void getGroupGroups(List *groupReturnList, List *groupList);

void buildGroup(Group *groupList, xmlNodePtr g_node);

int svgValidator(char *schemaFile, xmlDoc *file);

//Very important function to set a values to empty
void setListToEmpty(List* list);

char *validSVGToJSON(char* fileName, char *schemaFile);

char* SVGrectListToJSON(char* fileName, char *schemaFile);
char* SVGcircListToJSON(char* fileName, char *schemaFile);
char* SVGpathListToJSON(char* fileName, char *schemaFile);
char* SVGgroupListToJSON(char* fileName, char *schemaFile);

char* titleAndDesc(char* fileName, char *schemaFile);

char* showAttr(char* fileName, char *schemaFile, int index, char *type);
void editAttr(char* fileName, char *schemaFile, int index, char *type, char *name, char *value);


#endif