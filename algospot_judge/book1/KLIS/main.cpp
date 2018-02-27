/**
Retrospection: I made a mistake when getting length of lis.
In first call of the function getting length of lis should call through all indices.
Also, I made a mistake related to long long type. To express long long magic number, ll should be prefixed.

for test: 
1
500 2147483647
2000 20001 200004 200003 2000006 20000005 8 7 10 9 12 11 14 13 16 15 18 17 20 19 22 21 24 23 26 25 28 27 30 29 32 31 34 33 36 35 38 37 40 39 42 41 44 43 46 45 48 47 50 49 52 51 54 53 56 55 58 57 60 59 62 61 64 63 66 65 68 67 70 69 72 71 74 73 76 75 78 77 80 79 82 81 84 83 86 85 88 87 90 89 92 91 94 93 96 95 98 97 100 99 102 101 104 103 106 105 108 107 110 109 112 111 114 113 116 115 118 117 120 119 122 121 124 123 126 125 128 127 130 129 132 131 134 133 136 135 138 137 140 139 142 141 144 143 146 145 148 147 150 149 152 151 154 153 156 155 158 157 160 159 162 161 164 163 166 165 168 167 170 169 172 171 174 173 176 175 178 177 180 179 182 181 184 183 186 185 188 187 190 189 192 191 194 193 196 195 198 197 200 199 202 201 204 203 206 205 208 207 210 209 212 211 214 213 216 215 218 217 220 219 222 221 224 223 226 225 228 227 230 229 232 231 234 233 236 235 238 237 240 239 242 241 244 243 246 245 248 247 250 249 252 251 254 253 256 255 258 257 260 259 262 261 264 263 266 265 268 267 270 269 272 271 274 273 276 275 278 277 280 279 282 281 284 283 286 285 288 287 290 289 292 291 294 293 296 295 298 297 300 299 302 301 304 303 306 305 308 307 310 309 312 311 314 313 316 315 318 317 320 319 322 321 324 323 326 325 328 327 330 329 332 331 334 333 336 335 338 337 340 339 342 341 344 343 346 345 348 347 350 349 352 351 354 353 356 355 358 357 360 359 362 361 364 363 366 365 368 367 370 369 372 371 374 373 376 375 378 377 380 379 382 381 384 383 386 385 388 387 390 389 392 391 394 393 396 395 398 397 400 399 402 401 404 403 406 405 408 407 410 409 412 411 414 413 416 415 418 417 420 419 422 421 424 423 426 425 428 427 430 429 432 431 434 433 436 435 438 437 440 439 442 441 444 443 446 445 448 447 450 449 452 451 454 453 456 455 458 457 460 459 462 461 464 463 466 465 468 467 470 469 472 471 474 473 476 475 478 477 480 479 482 481 484 483 486 485 488 487 490 489 492 491 494 493 496 495 498 497 500 499
1
18 3
2000 20001 20004 20003 40006 70005 8 7 10 9 12 11 14 13 16 15 18 17
**/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

void init();
int getLisLen(int curPos);
long long getLisCntStartFrom(int curLen, int pos);
void fillSortedIndexSeq();
void fillSolutionWithIndex(int curLen, int curPos, int k, vector<int>& sol);
int seqLen, k;
int lisLen;
int seq[500];
int sortedIndexSeq[501];
long long lisCntCache[501][501];
int lisCache[501];

int main() {
	int C;
	vector< vector<int> > sols;
	cin >> C;
	sols.resize(C);
	for (int i=0; i<C; i++) {
		init();
		cin >> seqLen >> k;
		for (int j=0; j<seqLen; j++) {
			cin >> seq[j];
		}
		fillSortedIndexSeq();
		lisLen = getLisLen(-1);
		sols[i].clear();
		fillSolutionWithIndex(lisLen, 0, k-1, sols[i]);
		for (int j=0; j<sols[i].size(); j++) {
			sols[i][j] = seq[sortedIndexSeq[sols[i][j]]];
		} 
	}
	for (int i=0; i<C; i++) {
		cout << sols[i].size() << endl;
		for (int j=0; j<sols[i].size(); j++) {
			cout << sols[i][j];
			if (j+1 != sols[i].size())
				cout << " ";
		}
		cout << endl;
	}
}

void init() {
	for (int i=0; i<501; i++) {
		for (int j=0; j<501; j++) {
			lisCntCache[i][j] = -1;
		}
	}
	memset(lisCache, -1, sizeof(lisCache));
}

bool comparator ( const pair<int,int>& l, const pair<int,int>& r)
   { return l.second < r.second; }
void fillSortedIndexSeq() {
	pair<int,int> pairs[500];
	for (int i=0; i<seqLen; i++) {
        pairs[i] = pair<int,int>(i, seq[i]);
    }
	sort(pairs, pairs+seqLen, comparator);
	for (int i=0; i<seqLen; i++) {
		sortedIndexSeq[i] = pairs[i].first;
	}
}

int getLisLen(int curPos) {
	int maxLen = 1;
	if (curPos == -1) {
		for (int i=0; i<seqLen; i++) {
			maxLen = max(getLisLen(i), maxLen);
		}
		return maxLen;
	}
	int& ret = lisCache[curPos];
	if (ret != -1) return ret;
	int curVal = seq[curPos];
	for (int nextPos=curPos+1; nextPos<seqLen; nextPos++) {
		if (curVal < seq[nextPos]) {
			maxLen = max(maxLen, getLisLen(nextPos) + 1);
		}
	}
	ret = maxLen;
	return ret;
}

long long getLisCntStartFrom(int curLen, int pos) {
	if (curLen == 1)
		return 1;
	long long& ret = lisCntCache[curLen][pos];
	if (ret!=-1) return ret;
	int elem = seq[pos];
	long long sum = 0;
	for (int nextPos=pos+1; nextPos<seqLen; nextPos++) {
		if (elem < seq[nextPos]) {
			sum += getLisCntStartFrom(curLen-1, nextPos);
			if (0x123456789ll<sum) {
				sum = 0x123456789ll;
			}
		}
	}
	ret = sum;
	return ret;
}

void fillSolutionWithIndex(int curLen, int curPos, int k, vector<int>& sol) {
	if (curLen == 0)
		return;
	long long seqCnt;
	int i;
	int lastVal;
	if (curPos == 0)
		i = 0;
	else {
		lastVal =sol[curPos-1];
		i = sol[curPos-1]+1;
	}
	for (; i<seqLen; i++) { // sorted index seq's index: i, sortedIndexSeq[i]: seq's index
		if (curPos == 0 || sortedIndexSeq[lastVal]<sortedIndexSeq[i]) { // right from last index
			seqCnt = getLisCntStartFrom(curLen, sortedIndexSeq[i]);
			if (seqCnt <= (long long)k)
				k-=seqCnt;
			else {
				sol.push_back(i);
				break;
			}
		}
	}
	fillSolutionWithIndex(curLen-1, curPos+1, k, sol);
}
