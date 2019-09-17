package com.kakao.test.dto.component;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@ToString
@Getter
@Setter
@NoArgsConstructor
public class Elevator {
    private int id;
    private int floor;
    private List<Passenger> passengers;
    private String status;
}
