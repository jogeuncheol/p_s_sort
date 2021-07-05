# p_s_sort

### push_swap

|command|stack a|stack b|same time|
|-------|-|-|-|
|swap|sa|sb|ss|
|push|pa|pb|-|
|rotate|ra|rb|rr|
|reverse rotate|rra|rrb|rrr|

- swap : 스택의 상위 요소의 위치를 바꿈
- push : 스택으로 값을 넣음
- rotate : 스택의 값들의 위치가 하나씩 당겨짐 (n번째 요소는 n-1번 위치로, 1번은 n번 위치로, 2번은 1번 위치로)
- reverse rotate : 스택의 값들의 위치가 하나씩 밀어짐 (n번째 요소는 1번 위치로, 1번은 2번 위치로, 2번은 3번 위치로)

### example

|stack A|stack B|
|:-----:|:-----:|
|<span style="color:red">4</span>||
|2||
|5||

#### swap a, sa
|stack A|stack B|
|:-----:|:-----:|
|2||
|<span style="color:red">4</span>||
|5||

#### rotate a, ra
|stack A|stack B|
|:-----:|:-----:|
|<span style="color:red">4</span>||
|5||
|2||

- one more ra

|stack A|stack B|
|:-----:|:-----:|
|5||
|2||
|<span style="color:red">4</span>||

#### reverse rotate a, rra
|stack A|stack B|
|:-----:|:-----:|
|<span style="color:red">4</span>||
|5||
|2||

- one more rra

|stack A|stack B|
|:-----:|:-----:|
|2||
|<span style="color:red">4</span>||
|5||

#### push b, pb
|stack A|stack B|
|:-----:|:-----:|
|<span style="color:red">4</span>||
|5|2|

- one more pb

|stack A|stack B|
|:-----:|:-----:|
||<span style="color:red">4</span>|
|5|2|

|stack structure|||
|----|-----|-----|
|data|value|index|
|addr|prev|next|

- value : 랜덤 값 (정수 범위로 제한)
- index : 정렬 상태의 순서 정보
- next : 다음 노드의 주소
- prev : 이전 노드의 주소
