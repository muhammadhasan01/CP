// Official Solution
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
using lint = long long;
using pi = pair<lint, int>;
 
lint f(lint x){
	return (x + (x >> 20) + 12345) & ((1ll << 40) - 1);
}
 
vector<pi> seq = {
	pi(0x600DCAFE, 0),
 
pi(38312556854ll, 10006016), pi(167560289742ll, 20012407), pi(622741727028ll, 30040231), pi(13107744445ll, 40042828), pi(78802032994ll, 50056830), pi(310147760736ll, 60057167), pi(295498034ll, 70077203), pi(33681877906ll, 80089333), pi(151258698876ll, 90060816), pi(565345893787ll, 100089173), pi(10752858133ll, 110081437), pi(70512631458ll, 120091492), pi(280954761586ll, 130104565), pi(1022070324749ll, 140110603), pi(29466792348ll, 150119936), pi(136417233148ll, 160106697), pi(513107125545ll, 170101751), pi(8611289031ll, 180074324), pi(62966213954ll, 190070900), pi(254367017868ll, 200067362), pi(928397275086ll, 210056611), pi(25631359205ll, 220055532), pi(122903535528ll, 230050443), pi(465478252203ll, 240074925), pi(6660774750ll, 250065867), pi(56101519545ll, 260064780), pi(230202910861ll, 270039390), pi(843378208127ll, 280035570), pi(22143265079ll, 290032772), pi(110616850082ll, 300024176), pi(422200315823ll, 310020825), pi(4887295570ll, 320029221), pi(49853842669ll, 330043286), pi(208212155972ll, 340034384), pi(765903932490ll, 350030002), pi(18971471018ll, 360005307), pi(99457200140ll, 369996090), pi(382866491137ll, 379999366), pi(3274538358ll, 389993137), pi(44173156708ll, 399990656), pi(188203727777ll, 409994421), pi(695455204611ll, 420002512), pi(16084952347ll, 430005282), pi(89287883904ll, 439993029), pi(347092002761ll, 449966857), pi(1809716545ll, 459969609), pi(39010177057ll, 469968835), pi(170013125763ll, 479955292), pi(631344340292ll, 489947894), pi(13458634941ll, 499961506)};
 
int main(){
	lint n; cin >> n;
	lint ANS = 0;
	if (n >= 420420420) {
		lint p = (n - 420420420) / 364258418;
		n -= 364258418 * p;
		ANS += 182058608 * p;
	}
	lint x = seq[n / 20000000].first;
	ANS += seq[n / 20000000].second;
	for (int i = 0; i < n%20000000; i++) {
		if (x % 2 == 0) ANS++;
		x = f(x);
	}
	cout << ANS << endl;
}