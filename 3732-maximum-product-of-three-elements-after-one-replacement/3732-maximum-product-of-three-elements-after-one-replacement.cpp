class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        // 1. استخدام long long في كل مكان لمنع الـ Overflow
        vector<long long> p;
        for(int i = 0; i < nums.size(); i++) {
            // نأخذ القيمة المطلقة (Absolute) يدوياً
            if(nums[i] < 0) p.push_back((long long)nums[i] * -1);
            else p.push_back((long long)nums[i]);
        }

        // 2. ترتيب تنازلي كما فعلت
        sort(p.rbegin(), p.rend());

        long long val1 = p[0];
        long long val2 = p[1];

        // 3. تحديد الإشارة الأصلية للرقمين
        // سنفترض أنهما سالبان، وإذا وجدناهما في المصفوفة الأصلية كموجبين سنعدل الإشارة
        long long num1, num2;
        
        if (find(nums.begin(), nums.end(), -val1) != nums.end()) {
            num1 = -val1;
        } else {
            num1 = val1;
        }

        if (find(nums.begin(), nums.end(), -val2) != nums.end()) {
            // حالة خاصة: لو val1 و val2 نفس الرقم (مثلاً 100 و 100)
            // لازم نتأكد إن فيه نسختين سالبتين فعلاً في المصفوفة الأصلية
            if (val1 == val2) {
                int count = 0;
                for(int x : nums) if(x == -val1) count++;
                if(count >= 2) num2 = -val2;
                else num2 = val2;
            } else {
                num2 = -val2;
            }
        } else {
            num2 = val2;
        }

        long long t = num1 * num2;
        long long V = 100000;

        if(t < 0) {
            return t * -V; 
        } else {
            return t * V;  
        }
    }
};