package com.kakao.test.dto.component;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@ToString
@Getter
@Setter
@NoArgsConstructor
public class Command {
    @JsonProperty(value = "elevator_id")
    private int elevatorId;

    private String command;

    @JsonProperty(value = "call_ids")
    private List<Integer> callIds;
}
