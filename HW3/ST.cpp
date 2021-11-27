#include <bits/stdc++.h>
using namespace std;

#define NUM_OF_THR 1
#define NUM_OF_SEG 16

struct segment {
	int lef, rig;
	int* v;
};

void* bubble_sort(void* s) {
	segment now = *((segment*) s);

	for (int i = now.lef; i < now.rig; i++) {
		for (int j = i + 1; j < now.rig; j++) {
			if (now.v[i] > now.v[j]) swap(now.v[i], now.v[j]);
		}
	}
    return NULL;
}

struct twoSegment {
	int x1, y1;
	int x2, y2;
	int* v;
};

// Merge [x1, y1) && [x2, y2)
void* merge(void* s) {

	twoSegment now = *((twoSegment*) s);
	int* v = now.v;
	int x1 = now.x1, y1 = now.y1;
	int x2 = now.x2, y2 = now.y2;

	// cout << "Thread " << now.x1 << ' ' << now.y1 << ' ' << now.x2 << ' ' << now.y2 << endl;
	if (y1 != x2) {
		cout << y1 << ' ' << x2 << ' ';
		cout << "Not continuous segment! Can not be merge\n";
		exit(1);
	}

	vector<int> tmp; tmp.clear();
	while (x1 < y1 && x2 < y2) {
		if (v[x1] < v[x2]) {
			tmp.push_back(v[x1]);
			x1 ++;
		}
		else {
			tmp.push_back(v[x2]);
			x2 ++;
		}
	}
	while (x1 < y1) { tmp.push_back(v[x1]); x1++; };
	while (x2 < y2) { tmp.push_back(v[x2]); x2++; };

	for (int i = now.x1, j = 0; i < now.y2; i++, j++) v[i] = tmp[j];

    return NULL;
}

int main() {
	cin.tie(0), cout.sync_with_stdio(false);

	vector<int> k; k.clear();
	int x, n;
	while (cin >> x) k.push_back(x);
	n = (int) k.size();

	int* v = (int*) calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) v[i] = k[i];


    segment* segments = (segment*) calloc(NUM_OF_SEG, sizeof(segment));

	int m = n / NUM_OF_SEG;
	int lef = 0, rig = m;
    int seg_siz = 0;

	for (int i = 0; i < NUM_OF_SEG; i++) {
		if (i == NUM_OF_SEG - 1) rig = n;

		segments[i].lef = lef;
		segments[i].rig = rig;
		segments[i].v = v;

        bubble_sort((void*) &segments[i]);
        seg_siz += 1;

		lef = rig;
		rig = lef + m;
	}

	segment*    tmp = (segment*)    calloc(NUM_OF_SEG, sizeof(segment));
	twoSegment* tsg = (twoSegment*) calloc(NUM_OF_SEG, sizeof(twoSegment));

	while (seg_siz >= 2) {
		int p = 0, new_seg = 0;
		for (int i = 0; i < seg_siz; i += 2) {
			
			if (i == seg_siz - 1) {
				tmp[new_seg] = segments[i];
				new_seg ++;
				continue;
			}

			tsg[p].x1 = segments[i].lef; tsg[p].x2 = segments[i + 1].lef;
			tsg[p].y1 = segments[i].rig; tsg[p].y2 = segments[i + 1].rig;
			tsg[p].v = segments[i].v;

			// cout << tsg[p].x1 << ' ' << tsg[p].y1 << ' ' << tsg[p].x2 << ' ' << tsg[p].y2 << endl;
			
			tmp[new_seg++] = (segment){ tsg[p].x1, tsg[p].y2, tsg[p].v };
            
            merge((void*) &tsg[p]);
			p += 1;
		}
        
        segment* tp = segments;
        segments = tmp;
        tmp = tp;
        seg_siz = new_seg;
	}
	for (int i = 0; i < n; i++) cout << v[i] << ' ';
	cout << '\n';

	free(tmp);
	free(tsg);
    free(segments);
	return 0;
}
