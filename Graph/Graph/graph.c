#include "stdio.h"
#include "windows.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef int InfoType;//边类型
typedef char* VertexType;//节点存储信息
#define MAX_VERTEX_NUM 30
typedef enum{unvisited,visited}VisitIf;
typedef struct EBox {
	VisitIf mark;	//访问标记
	int ivex, jvex;	//该边依附于的两个顶点的位置
	struct EBox *ilink, *jlink;	//分别指向依附于这两个顶点的下一条边
	InfoType *info;	//该边信息指针
}EBox;
typedef struct VexBox {
	VertexType data[20];
	EBox *firstedge;	//指向第一条依附于该顶点的边
}VexBox;
typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum;	//无向图的当前定点数和边数
}AMLGraph;
//图的初始化
Status InitAMLGraph(AMLGraph *G) {
	(*G).vexnum = 25;
	(*G).edgenum = 30;
	(*G).adjmulist[0].data[20] ="哈尔滨";
	(*G).adjmulist[0].firstedge->mark = unvisited;
	*((*G).adjmulist[0].firstedge->info) = 242;
	(*G).adjmulist[0].firstedge->ivex = 0;
	(*G).adjmulist[0].firstedge->jvex = 1;
	(*G).adjmulist[0].firstedge->ilink = NULL;
	(*G).adjmulist[0].firstedge->jlink = (*G).adjmulist[1].firstedge;
	(*G).adjmulist[1].data[20] = "长春";
	(*G).adjmulist[1].firstedge->mark = unvisited;
	*((*G).adjmulist[1].firstedge->info) = 305;
	(*G).adjmulist[1].firstedge->ivex = 1;
	(*G).adjmulist[1].firstedge->jvex = 2;
	(*G).adjmulist[1].firstedge->ilink = (*G).adjmulist[0].firstedge;
	(*G).adjmulist[1].firstedge->jlink = (*G).adjmulist[2].firstedge;
	(*G).adjmulist[2].data[20] = "沈阳";
	(*G).adjmulist[2].firstedge->mark = unvisited;
	*((*G).adjmulist[2].firstedge->info) = 704;
	(*G).adjmulist[2].firstedge->ivex = 2;
	(*G).adjmulist[2].firstedge->jvex = 4;
	(*G).adjmulist[2].firstedge->ilink = (*G).adjmulist[3].firstedge;
	(*G).adjmulist[2].firstedge->jlink = (*G).adjmulist[5].firstedge;
	(*G).adjmulist[3].data[20] = "大连";
	(*G).adjmulist[3].firstedge->mark = unvisited;
	*((*G).adjmulist[3].firstedge->info) = 397;
	(*G).adjmulist[3].firstedge->ivex = 3;
	(*G).adjmulist[3].firstedge->jvex = 2;
	(*G).adjmulist[3].firstedge->ilink = NULL;
	(*G).adjmulist[3].firstedge->jlink = (*G).adjmulist[4].firstedge;
	(*G).adjmulist[4].data[20] = "天津";
	(*G).adjmulist[4].firstedge->mark = unvisited;
	*((*G).adjmulist[4].firstedge->info) = 674;
	(*G).adjmulist[4].firstedge->ivex = 4;
	(*G).adjmulist[4].firstedge->jvex = 5;
	(*G).adjmulist[4].firstedge->ilink = (*G).adjmulist[14].firstedge;
	(*G).adjmulist[4].firstedge->jlink = (*G).adjmulist[6].firstedge;
	(*G).adjmulist[5].data[20] = "徐州";
	(*G).adjmulist[5].firstedge->mark = unvisited;
	*((*G).adjmulist[5].firstedge->info) = 651;
	(*G).adjmulist[5].firstedge->ivex = 5;
	(*G).adjmulist[5].firstedge->jvex = 6;
	(*G).adjmulist[5].firstedge->ilink = (*G).adjmulist[13].firstedge;
	(*G).adjmulist[5].firstedge->jlink = (*G).adjmulist[7].firstedge;
	(*G).adjmulist[6].data[20] = "上海";
	(*G).adjmulist[6].firstedge->mark = unvisited;
	*((*G).adjmulist[6].firstedge->info) = 825;
	(*G).adjmulist[6].firstedge->ivex = 6;
	(*G).adjmulist[6].firstedge->jvex = 7;
	(*G).adjmulist[6].firstedge->ilink = (*G).adjmulist[5].firstedge;
	(*G).adjmulist[6].firstedge->jlink = (*G).adjmulist[9].firstedge;
	(*G).adjmulist[7].data[20] = "南昌";
	(*G).adjmulist[7].firstedge->mark = unvisited;
	*((*G).adjmulist[7].firstedge->info) = 367;
	(*G).adjmulist[7].firstedge->ivex = 7;
	(*G).adjmulist[7].firstedge->jvex = 9;
	(*G).adjmulist[7].firstedge->ilink = (*G).adjmulist[6].firstedge;
	(*G).adjmulist[7].firstedge->jlink = (*G).adjmulist[20].firstedge;
	(*G).adjmulist[8].data[20] = "福州";
	(*G).adjmulist[8].firstedge->mark = unvisited;
	*((*G).adjmulist[8].firstedge->info) = 622;
	(*G).adjmulist[8].firstedge->ivex = 8;
	(*G).adjmulist[8].firstedge->jvex = 7;
	(*G).adjmulist[8].firstedge->ilink = NULL;
	(*G).adjmulist[8].firstedge->jlink = (*G).adjmulist[9].firstedge;
	(*G).adjmulist[9].data[20] = "株洲";
	(*G).adjmulist[9].firstedge->mark = unvisited;
	*((*G).adjmulist[9].firstedge->info) = 902;
	(*G).adjmulist[9].firstedge->ivex = 9;
	(*G).adjmulist[9].firstedge->jvex = 20;
	(*G).adjmulist[9].firstedge->ilink = (*G).adjmulist[7].firstedge;
	(*G).adjmulist[9].firstedge->jlink = (*G).adjmulist[18].firstedge;
	(*G).adjmulist[10].data[20] = "广州";
	(*G).adjmulist[10].firstedge->mark = unvisited;
	*((*G).adjmulist[10].firstedge->info) = 675;
	(*G).adjmulist[10].firstedge->ivex = 10;
	(*G).adjmulist[10].firstedge->jvex = 9;
	(*G).adjmulist[10].firstedge->ilink = (*G).adjmulist[11].firstedge;
	(*G).adjmulist[10].firstedge->jlink = (*G).adjmulist[21].firstedge;
	(*G).adjmulist[11].data[20] = "深圳";
	(*G).adjmulist[11].firstedge->mark = unvisited;
	*((*G).adjmulist[11].firstedge->info) = 140;
	(*G).adjmulist[11].firstedge->ivex = 11;
	(*G).adjmulist[11].firstedge->jvex = 10;
	(*G).adjmulist[11].firstedge->ilink = NULL;
	(*G).adjmulist[11].firstedge->jlink = (*G).adjmulist[9].firstedge;
	(*G).adjmulist[12].data[20] = "武汉";
	(*G).adjmulist[12].firstedge->mark = unvisited;
	*((*G).adjmulist[12].firstedge->info) = 409;
	(*G).adjmulist[12].firstedge->ivex = 12;
	(*G).adjmulist[12].firstedge->jvex = 9;
	(*G).adjmulist[12].firstedge->ilink = (*G).adjmulist[13].firstedge;
	(*G).adjmulist[12].firstedge->jlink = (*G).adjmulist[21].firstedge;
	(*G).adjmulist[13].data[20] = "郑州";
	(*G).adjmulist[13].firstedge->mark = unvisited;
	*((*G).adjmulist[13].firstedge->info) = 534;
	(*G).adjmulist[13].firstedge->ivex = 13;
	(*G).adjmulist[13].firstedge->jvex = 12;
	(*G).adjmulist[13].firstedge->ilink = (*G).adjmulist[14].firstedge;
	(*G).adjmulist[13].firstedge->jlink = (*G).adjmulist[9].firstedge;
	(*G).adjmulist[14].data[20] = "北京";
	(*G).adjmulist[14].firstedge->mark = unvisited;
	*((*G).adjmulist[14].firstedge->info) = 695;
	(*G).adjmulist[14].firstedge->ivex = 14;
	(*G).adjmulist[14].firstedge->jvex = 13;
	(*G).adjmulist[14].firstedge->ilink = (*G).adjmulist[15].firstedge;
	(*G).adjmulist[14].firstedge->jlink = (*G).adjmulist[17].firstedge;
	(*G).adjmulist[15].data[20] = "呼和浩特";
	(*G).adjmulist[15].firstedge->mark = unvisited;
	*((*G).adjmulist[15].firstedge->info) = 668;
	(*G).adjmulist[15].firstedge->ivex = 15;
	(*G).adjmulist[15].firstedge->jvex = 14;
	(*G).adjmulist[15].firstedge->ilink = (*G).adjmulist[16].firstedge;
	(*G).adjmulist[15].firstedge->jlink = (*G).adjmulist[4].firstedge;
	(*G).adjmulist[16].data[20] = "兰州";
	(*G).adjmulist[16].firstedge->mark = unvisited;
	*((*G).adjmulist[16].firstedge->info) = 1145;
	(*G).adjmulist[16].firstedge->ivex = 16;
	(*G).adjmulist[16].firstedge->jvex = 15;
	(*G).adjmulist[16].firstedge->ilink = (*G).adjmulist[17].firstedge;
	(*G).adjmulist[16].firstedge->jlink = (*G).adjmulist[14].firstedge;
	(*G).adjmulist[17].data[20] = "西安";
	(*G).adjmulist[17].firstedge->mark = unvisited;
	*((*G).adjmulist[17].firstedge->info) = 676;
	(*G).adjmulist[17].firstedge->ivex = 17;
	(*G).adjmulist[17].firstedge->jvex = 16;
	(*G).adjmulist[17].firstedge->ilink = (*G).adjmulist[13].firstedge;
	(*G).adjmulist[17].firstedge->jlink = (*G).adjmulist[23].firstedge;
	(*G).adjmulist[18].data[20] = "成都";
	(*G).adjmulist[18].firstedge->mark = unvisited;
	*((*G).adjmulist[18].firstedge->info) = 842;
	(*G).adjmulist[18].firstedge->ivex = 18;
	(*G).adjmulist[18].firstedge->jvex = 17;
	(*G).adjmulist[18].firstedge->ilink = (*G).adjmulist[20].firstedge;
	(*G).adjmulist[18].firstedge->jlink = (*G).adjmulist[13].firstedge;
	(*G).adjmulist[19].data[20] = "昆明";
	(*G).adjmulist[19].firstedge->mark = unvisited;
	*((*G).adjmulist[19].firstedge->info) = 1100;
	(*G).adjmulist[19].firstedge->ivex = 19;
	(*G).adjmulist[19].firstedge->jvex = 18;
	(*G).adjmulist[19].firstedge->ilink = (*G).adjmulist[20].firstedge;
	(*G).adjmulist[19].firstedge->jlink = (*G).adjmulist[20].firstedge;
	(*G).adjmulist[20].data[20] = "贵阳";
	(*G).adjmulist[20].firstedge->mark = unvisited;
	*((*G).adjmulist[20].firstedge->info) = 639;
	(*G).adjmulist[20].firstedge->ivex = 20;
	(*G).adjmulist[20].firstedge->jvex = 19;
	(*G).adjmulist[20].firstedge->ilink = (*G).adjmulist[21].firstedge;
	(*G).adjmulist[20].firstedge->jlink = (*G).adjmulist[18].firstedge;
	(*G).adjmulist[21].data[20] = "柳州";
	(*G).adjmulist[21].firstedge->mark = unvisited;
	*((*G).adjmulist[21].firstedge->info) = 607;
	(*G).adjmulist[21].firstedge->ivex = 21;
	(*G).adjmulist[21].firstedge->jvex = 20;
	(*G).adjmulist[21].firstedge->ilink = (*G).adjmulist[9].firstedge;
	(*G).adjmulist[21].firstedge->jlink = (*G).adjmulist[9].firstedge;
	(*G).adjmulist[22].data[20] = "南宁";
	(*G).adjmulist[22].firstedge->mark = unvisited;
	*((*G).adjmulist[22].firstedge->info) = 255;
	(*G).adjmulist[22].firstedge->ivex = 22;
	(*G).adjmulist[22].firstedge->jvex = 21;
	(*G).adjmulist[22].firstedge->ilink = NULL;
	(*G).adjmulist[22].firstedge->jlink = (*G).adjmulist[20].firstedge;
	(*G).adjmulist[23].data[20] = "西宁";
	(*G).adjmulist[23].firstedge->mark = unvisited;
	*((*G).adjmulist[23].firstedge->info) = 216;
	(*G).adjmulist[23].firstedge->ivex = 23;
	(*G).adjmulist[23].firstedge->jvex = 16;
	(*G).adjmulist[23].firstedge->ilink = NULL;
	(*G).adjmulist[23].firstedge->jlink = (*G).adjmulist[17].firstedge;
	(*G).adjmulist[24].data[20] = "乌鲁木齐";
	(*G).adjmulist[24].firstedge->mark = unvisited;
	*((*G).adjmulist[24].firstedge->info) = 1892;
	(*G).adjmulist[24].firstedge->ivex = 24;
	(*G).adjmulist[24].firstedge->jvex = 16;
	(*G).adjmulist[24].firstedge->ilink = NULL;
	(*G).adjmulist[24].firstedge->jlink = (*G).adjmulist[17].firstedge;
	return OK;
}
//深度优先遍历
//广度优先遍历
int main() {
	printf("******************图的深度和广度优先遍历******************\n");
	AMLGraph G;
	printf("系统正在输入地图.......\n");
	Sleep(1000);
	InitAMLGraph(&G);
	printf("系统输入地图成功\n");
	system("pause");
	return 0;
}