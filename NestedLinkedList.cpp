#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int classNumber=1;

struct student{
	char studentname[100];
	student *studentNext, *studentPrev;
};

struct classroom{
	char className[100];
	int classNumber;
	classroom *classroomNext, *classroomPrev;
	student *studentHead, *studentTail, *studentCurr;
}*classroomHead, *classroomTail, *classroomCurr;

void printData(){
	classroomCurr = classroomHead;
	while(classroomCurr){
		printf("%d. %s\n", classroomCurr->classNumber, classroomCurr->className);
		classroomCurr->studentCurr = classroomCurr->studentHead;
		while(classroomCurr->studentCurr){
			printf("  - %s\n", classroomCurr->studentCurr->studentname);
			classroomCurr->studentCurr = classroomCurr->studentCurr->studentNext;
		}
		classroomCurr=classroomCurr->classroomNext;
	}
}

void pushClassRoom(char classroomname[]){
	classroomCurr = (classroom *)malloc(sizeof(classroom));
	strcpy(classroomCurr->className, classroomname);
	classroomCurr->classNumber = classNumber; classNumber++;
	classroomCurr->classroomNext = classroomCurr->classroomPrev = NULL;
	classroomCurr->studentHead = classroomCurr->studentTail = classroomCurr->studentCurr = NULL;
	
	if(classroomHead==NULL){
		classroomHead = classroomTail = classroomCurr;
	}else{
		classroomTail->classroomNext = classroomCurr;
		classroomCurr->classroomPrev = classroomTail;
		classroomTail = classroomCurr;
	}
}

void pushStudent(int targetClassNumber, char studentName[]){
	int found=-1;
	classroomCurr = classroomHead;
	while(classroomCurr!=NULL && found==-1){
		if(classroomCurr->classNumber==targetClassNumber){ found=1; break; } 
		classroomCurr=classroomCurr->classroomNext;
	}
	if(found==1){
		classroomCurr->studentCurr = (student*)malloc(sizeof(student));
		strcpy(classroomCurr->studentCurr->studentname, studentName);

		classroomCurr->studentCurr->studentNext = classroomCurr->studentCurr->studentPrev = NULL;

		if(classroomCurr->studentHead==NULL){
			classroomCurr->studentHead = classroomCurr->studentTail = classroomCurr->studentCurr;
		}else{
			classroomCurr->studentTail->studentNext = classroomCurr->studentCurr;
			classroomCurr->studentCurr->studentPrev = classroomCurr->studentTail;
			classroomCurr->studentTail = classroomCurr->studentCurr;
		}
	}else{
		printf("Class not found.\n");
	}
}

void deleteClassRoom(int targetClassNumber){
	int found=-1;
	student *tempStudent;
	classroom *tempClass;
	classroomCurr = classroomHead;
	while(classroomCurr!=NULL){
		if(classroomCurr->classNumber == targetClassNumber){ found=1; break; }
		classroomCurr = classroomCurr->classroomNext;
	}
	if(found==1){
		while(classroomCurr->studentHead!=NULL){
			tempStudent = classroomCurr->studentHead;
			if(classroomCurr->studentHead==classroomCurr->studentTail){
				classroomCurr->studentHead=classroomCurr->studentTail=NULL;
			}else{
				classroomCurr->studentHead=classroomCurr->studentHead->studentNext;
			}
			free(tempStudent);
		}
		tempClass = classroomCurr;
		if(classroomHead==classroomTail){
			classroomHead = classroomTail = NULL;
		}else if(classroomCurr==classroomHead){
			classroomHead=classroomHead->classroomNext;
			classroomHead->classroomPrev=NULL;
		}else if(classroomCurr==classroomTail){
			classroomTail=classroomTail->classroomPrev;
			classroomTail->classroomNext=NULL;
		}else{
			classroomCurr->classroomPrev->classroomNext = classroomCurr->classroomNext;
			classroomCurr->classroomNext->classroomPrev = classroomCurr->classroomPrev;
		}
		free(tempClass);
	}else{
		printf("Class not found.\n");
	}
}

void deleteStudent(int targetClassNumber, char studentName[]){
	int foundClass=-1;
	int foundStudent=-1;
	student *tempStudent;

	classroomCurr = classroomHead;
	while(classroomCurr!=NULL){
		if(classroomCurr->classNumber == targetClassNumber){ foundClass=1; break; }
		classroomCurr = classroomCurr->classroomNext;
	}
	if(foundClass==1){
		classroomCurr->studentCurr = classroomCurr->studentHead;
		while(classroomCurr->studentCurr!=NULL){
			if(strcmpi(classroomCurr->studentCurr->studentname,studentName)==0){ foundStudent=1; break; }
			classroomCurr->studentCurr = classroomCurr->studentCurr->studentNext;
		}
		if(foundStudent==1){
			tempStudent = classroomCurr->studentCurr;
			if(classroomCurr->studentHead==classroomCurr->studentTail){
				classroomCurr->studentHead = classroomCurr->studentTail = NULL;
			}else if(classroomCurr->studentCurr == classroomCurr->studentHead){
				classroomCurr->studentHead = classroomCurr->studentHead->studentNext;
				classroomCurr->studentHead->studentPrev = NULL;
			}else if(classroomCurr->studentCurr == classroomCurr->studentTail){
				classroomCurr->studentTail = classroomCurr->studentTail->studentPrev;
				classroomCurr->studentTail->studentNext = NULL;
			}else{
				classroomCurr->studentCurr->studentPrev->studentNext = classroomCurr->studentCurr->studentNext;
				classroomCurr->studentCurr->studentNext->studentPrev = classroomCurr->studentCurr->studentPrev;
			}
			free(tempStudent);
		}else{
			printf("Student not found.\n");
		}
	}else{
		printf("Class not found.\n");
	}
}

int main(){
	pushClassRoom("XII A");
	pushClassRoom("XII B");
	pushClassRoom("XII C");
	pushStudent(1, "Hery Vandoro");
	pushStudent(1, "Tono Budiman");
	pushStudent(3, "Tini Hartini");
	pushStudent(2, "Susi Suherman");
	pushStudent(2, "John Doe");
	
	deleteStudent(2, "Foo Bar");
	deleteStudent(1, "Hery Vandoro");

	deleteClassRoom(2);

	pushClassRoom("XII D");
	printData();
	getchar();
}