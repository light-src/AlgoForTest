package com.kakao.test.dto;

import com.kakao.test.dto.component.Elevator;
import com.kakao.test.dto.component.Passenger;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@ToString
@Getter
@Setter
@NoArgsConstructor
public class OnCallsDto {
    private String token;
    private int timestamp;
    private List<Elevator> elevators;
    private List<Passenger> calls;
    private boolean is_end;
}
