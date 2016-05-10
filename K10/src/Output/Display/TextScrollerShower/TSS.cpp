/*
 * TSS.cpp
 *
 *  Created on: 10-mrt.-2016
 *      Author: david12
 */

#include "TSS.h"

bool toset[][8][8]={
		{	{false,false,false,false,false,false,false,false},
			{false,false,true ,true ,true ,false,false,false},
			{false,false,false,true ,true ,false,false,false},
			{false,false,false,true ,true ,false,false,false},
			{false,false,false,true ,true ,false,false,false},
			{false,false,false,true ,true ,false,false,false},
			{false,false,true ,true ,true ,true ,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,true ,true ,true ,true ,true ,true ,false},
			{false,true ,false,false,false,false,true ,false},
			{false,false,false,false,true ,true ,true ,false},
			{false,true ,true ,true ,false,false,false,false},
			{false,true ,false,false,false,false,false,false},
			{false,true ,true ,true ,true ,true ,true ,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},},

		{	{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},
			{false,false,false,false,false,false,false,false},}
};

TSS::TSS() {
	// TODO Auto-generated constructor stub

}

void TSS::SetInt(int teken,uint16_t collor,uint16_t* pixel[8][8]){
	for(int a=0;a!=8;a++)
		for(int b=0;b!=8;b++)
			if(toset[teken][a][b])
				;//pixel[a][b]=collor; TODO
}

TSS::~TSS() {
	// TODO Auto-generated destructor stub
}

