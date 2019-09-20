package com.kakao.test.dto.component;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@ToString
@Getter
@Setter
@NoArgsConstructor
public class Passenger {
    private int id;
    private int timestamp;
    private int start;
    private int end;
}
