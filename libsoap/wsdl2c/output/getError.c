/** Generated by xsd2c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getError.h"


struct getError* getError_Create()
{
	struct getError* _res;
	_res = (struct getError*)malloc(sizeof(struct getError));

	_res->in0 = 0;

	return _res;
}

void getError_Free(struct getError* obj)
{
	if (obj == NULL) return;
	free(obj);
}

void getError_Sax_Serialize(struct getError* obj,
		 const char *root_element_name,
		 void (*OnStartElement)(const char* element_name, int attr_count, char **keys, char **values, void* userData),
		 void (*OnCharacters)(const char* element_name, const char* chars, void* userData),
		 void (*OnEndElement)(const char* element_name, void* userData),
		 void* userData)
{
	int attrCount, curCount;
	char **keys;
	char **values;
	char buffer[255];


	attrCount = 0;

	keys = (char**)malloc(sizeof(char*)*attrCount);
	values = (char**)malloc(sizeof(char*)*attrCount);

	curCount = 0;


	OnStartElement(root_element_name, attrCount, keys, values, userData);

	OnStartElement("in0", 0, NULL, NULL, userData);
	sprintf(buffer, "%d", obj->in0);
	OnCharacters("in0", buffer, userData);
	OnEndElement("in0", userData);

	OnEndElement(root_element_name, userData);
}

#ifndef _DESERIALIZER_DISABLED_

struct getError* getError_Deserialize(xmlNodePtr xmlRoot)
{
	xmlNodePtr cur;
	xmlChar *key;
	struct getError* obj;
	obj = getError_Create();
	cur = xmlRoot->xmlChildrenNode;
	while (cur != NULL) {
		if (cur->type != XML_ELEMENT_NODE) {
			cur = cur->next;
			continue;
		}
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"in0"))){
			key = xmlNodeListGetString(cur->doc, cur->xmlChildrenNode, 1);
			getError_Set_in0(obj, atoi((const char*)key));
			/*xmlFree(key);*/
		}
	// TODO: 
		cur = cur->next;
	}
	return obj;
}

#endif
int getError_Get_in0(struct getError* obj)
{
	return obj->in0;
}

void getError_Set_in0(struct getError* obj, int in0)
{
	obj->in0 = in0;
}

