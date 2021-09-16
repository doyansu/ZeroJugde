#include <stdio.h>
#include <stdlib.h>

typedef struct _Node_
{
	int minTurn;
	char chDir;
} Node;

Node *pMinTurn = NULL;
int nRows = 0, nCols = 0;

void CalculateMinTurn(int curRow, int curCol)
{
	if (pMinTurn[curRow*nCols + curCol].chDir == 'X')
		return -1;
	int minTurn = nRows*nCols;
	if (curRow > 0 && curRow < nRows && pMinTurn[(curRow - 1)*nCols + curCol].chDir != '\0' &&  pMinTurn[(curRow - 1)*nCols + curCol].chDir != 'X')   // from top (to down)
	{
		if (pMinTurn[(curRow - 1)*nCols + curCol].chDir == 'D' && pMinTurn[(curRow - 1)*nCols + curCol].minTurn < minTurn)
			minTurn = pMinTurn[(curRow - 1)*nCols + curCol].minTurn, pMinTurn[curRow*nCols + curCol].chDir = 'D';
		else if (pMinTurn[(curRow - 1)*nCols + curCol].chDir != 'D' && pMinTurn[(curRow - 1)*nCols + curCol].minTurn + 1 <minTurn)
			minTurn = pMinTurn[(curRow - 1)*nCols + curCol].minTurn + 1, pMinTurn[curRow*nCols + curCol].chDir = 'D';
	}
	if (curCol > 0 && curCol < nCols && pMinTurn[curRow * nCols + curCol - 1].chDir != '\0' && pMinTurn[curRow * nCols + curCol - 1].chDir != 'X')   // from left (to right)
	{
		if (pMinTurn[curRow * nCols + curCol - 1].chDir == 'R' && pMinTurn[curRow * nCols + curCol - 1].minTurn < minTurn)
			minTurn = pMinTurn[curRow * nCols + curCol - 1].minTurn, pMinTurn[curRow*nCols + curCol].chDir = 'R';
		else if(pMinTurn[curRow * nCols + curCol - 1].chDir != 'R' && pMinTurn[curRow * nCols + curCol - 1].minTurn + 1 < minTurn)
			minTurn = pMinTurn[curRow * nCols + curCol - 1].minTurn + 1, pMinTurn[curRow*nCols + curCol].chDir = 'R';
	}
	if (curCol >= 0 && curCol < nCols - 1 && pMinTurn[curRow * nCols + curCol + 1].chDir != '\0' && pMinTurn[curRow * nCols + curCol + 1].chDir != 'X')   // from right (to left)
	{
		if (pMinTurn[curRow * nCols + curCol + 1].chDir == 'L' && pMinTurn[curRow * nCols + curCol + 1].minTurn < minTurn)
			minTurn = pMinTurn[curRow * nCols + curCol + 1].minTurn, pMinTurn[curRow*nCols + curCol].chDir = 'L';
		else if (pMinTurn[curRow * nCols + curCol + 1].chDir != 'L' && pMinTurn[curRow * nCols + curCol + 1].minTurn + 1 < minTurn)
			minTurn = pMinTurn[curRow * nCols + curCol + 1].minTurn + 1, pMinTurn[curRow*nCols + curCol].chDir = 'L';
	}
	if (minTurn < nRows*nCols)
		pMinTurn[curRow*nCols + curCol].minTurn = minTurn;
	else
		pMinTurn[curRow*nCols + curCol].minTurn = -1;
}

void main()
{
	while (scanf("%d %d", &nRows, &nCols) != EOF)
	{
		pMinTurn = (Node *)calloc(nRows*nCols, sizeof(Node));

		// Read start and end point
		int stPoint, endPoint;
		scanf("%d %d", &stPoint, &endPoint);
		pMinTurn[stPoint].minTurn = 0;
		pMinTurn[stPoint].chDir = 'D';

		// Read the positions of obstacles
		int nObstacle = 0;
		scanf("%d", &nObstacle);
		for (int k = 0; k < nObstacle; k++)
		{
			int xRow = 0, yCol = 0;
			scanf("%d %d", &xRow, &yCol);
			pMinTurn[xRow*nCols + yCol].minTurn = -1;
			pMinTurn[xRow*nCols + yCol].chDir = 'X';
		}

		for (int r = 0; r < nRows; r++)
		{
			for (int c = 0; c < nCols; c++)
			{
				if (r == 0 && c == stPoint)
					continue;
				CalculateMinTurn(r, c);
			}
			for (int c = nCols-1; c >=0; c--)
			{
				if (r == 0 && c == stPoint)
					continue;
				CalculateMinTurn(r, c);
			}
		}

		printf("%d\n", pMinTurn[(nRows - 1)*nCols + endPoint]);
		free(pMinTurn);
	}
}
