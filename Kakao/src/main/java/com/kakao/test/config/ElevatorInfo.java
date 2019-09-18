package com.kakao.test.config;

import com.kakao.test.dto.component.Elevator;
import com.kakao.test.dto.component.Passenger;
import org.springframework.stereotype.Component;

import java.util.ArrayList;
import java.util.List;

@Component
public class ElevatorInfo {
    public static List<Elevator> elevators = new ArrayList<>();
    public static List<Passenger> passengers = new ArrayList<>();
}
