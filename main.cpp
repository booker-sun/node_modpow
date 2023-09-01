#include <iostream>
#include "crypto-bn/bn.h"
#include "crypto-curve/curve.h"
using safeheron::bignum::BN;
using safeheron::curve::Curve;
using safeheron::curve::CurvePoint;
using safeheron::curve::CurveType;

int main() {
    // (1001, 9907) = -1
    BN k(1001);
    BN n(9907);
    BN n1 = BN::FromDecStr("351236171680578937197272793988364310158344798196852032811622206579");
    BN n2 = BN::FromDecStr("531137992816767098689588206552468627329593117727031923199444138200");
    BN n3 = BN::FromDecStr("206552468627329593117727031923199444195931177270319231994441382004");
    BN result = n1.PowM(n2,n3);
    std::string s;
    result.ToHexStr(s);
    std::cout << s << std::endl;
    CurvePoint p0(BN("cef66d6b2a3a993e591214d1ea223fb545ca6c471c48306e4c36069404c5723f", 16),
                  BN("878662a229aaae906e123cdd9d3b4c10590ded29fe751eeeca34bbaa44af0773", 16),
                  CurveType::P256);
    // p1 = g^100
    CurvePoint p1(BN("490a19531f168d5c3a5ae6100839bb2d1d920d78e6aeac3f7da81966c0f72170", 16),
                  BN("bbcd2f21db581bd5150313a57cfa2d9debe20d9f460117b588fcf9b0f4377794", 16),
                  CurveType::P256);
    // p2 = g^1000
    CurvePoint p2(BN("b8fa1a4acbd900b788ff1f8524ccfff1dd2a3d6c917e4009af604fbd406db702", 16),
                  BN("9a5cc32d14fc837266844527481f7f06cb4fb34733b24ca92e861f72cc7cae37", 16),
                  CurveType::P256);
    CurvePoint p3(CurveType::P256);
    p3 = p0;
    for(int i = 0; i < 9; i++){
        p3 += p0;
    }
    return 0;
}
