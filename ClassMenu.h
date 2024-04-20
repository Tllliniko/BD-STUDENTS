//����� ��� ����
#pragma once
#include "windows.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "ClassEditData.h"
#include "ClassList.h"

class ClassMenu
{
private:
	string upTitle; //��������� ���� (������)
	ClassList *items; //������ ����  
	string downTitle; //���������  ���� (�����)
	
public:
	ClassMenu(string _upTitle){	
		upTitle = move(_upTitle);
		items = new ClassList();
		//upTitle =  _upTitle; // ��� �� ���� ... �����;(
	}
	ClassMenu(): ClassMenu("������� ����"){
		downTitle = "�������� ����� �� ���� (�����): ";
	}
	~ClassMenu() {
		delete items;
	}
	void addMenuItem(string _item) {
		items->push_back(_item);
	}
	void draw(){
		system("cls");
		cout << upTitle << endl;
		items->printItems4Menu();
		cout << downTitle << endl;
	}
	int run() {
		draw();
		ClassEditData* cl = new ClassEditData();
		cl->setLabel("������� �����");
		int min=0, max = items->getCount();
		int selectItem = cl->getData(editType::onlyDigit, min, max);
		delete cl;
		return selectItem;
	}
};