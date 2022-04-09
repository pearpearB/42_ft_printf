# 42_printf

Summary: This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future projects without the fear of being flagged as a cheater.

요약 : 이 프로젝트는 꽤 단순합니다. 여러분은 printf 함수를 직접 구현하시면 됩니다. 희망컨대 여러분들은 cheater로 지목될 수 있다는 두려움 없이 추후 프로젝트에서 이것을 재활용할 수 있습니다.

You will mainly learn how to use variadic arguments.

여러분은 주로 가변 인자 (variadic arguments) 를 사용하는 방법에 대해 배울 것입니다.

구현하기
1. 고정인자를 읽어 %를 만나기 전까지 출력,
2. %를 만나면 자료형에 따라 분기,(가변인자 자료형에 따라 꺼냄)
3. 해당 자료형에 맞게 출력,
4. 리턴값은? 출력된 문자열의길이(공백 개행 등 포함), 에러시 -1
