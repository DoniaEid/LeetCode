class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        vector<long long> p; // تعديل النوع لـ long long لمنع الـ Overflow
        for(int i=0; i < nums.size(); i++){
            if(nums[i] < 0){
                p.push_back((long long)nums[i] * -1); // تصحيح push_back وضرب long long
            }
            else{
                p.push_back((long long)nums[i]);
            }
        }
        
        sort(p.rbegin(), p.rend());
        
        long long num1 = p[0];
        long long num2 = p[1];
        
        // البحث عن num1*-1 في المصفوفة الأصلية للتأكد من إشارته
        if (find(nums.begin(), nums.end(), (int)(num1 * -1)) == nums.end()) {
            // لو ملقناش النسخة السالبة، يبقى هو كان موجب أصلاً، نسيبه زي ما هو
        } else {
            // لو لقيناه، يبقى نرجعه لسالب
            num1 *= -1;
        }
        
        // البحث عن num2*-1 في المصفوفة الأصلية
        if (find(nums.begin(), nums.end(), (int)(num2 * -1)) == nums.end()) {
            // موجب
        } else {
            // لو لقيناه، نرجعه لسالب
            // تنبيه: لو num1 و num2 نفس الرقم، الـ find هيلاقيه دايماً، بس كبدايه ده هيمشيك صح
            num2 *= -1;
        }
        
        long long t = num1 * num2;
        
        if(t < 0){
            return t * -100000; // تصحيح 100000 (بدون نقطة)
        }
        else{
            return t * 100000;
        }
    }
};