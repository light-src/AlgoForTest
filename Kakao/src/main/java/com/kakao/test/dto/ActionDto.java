package com.kakao.test.dto;

import com.kakao.test.dto.component.Command;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@ToString
@Getter
@Setter
@NoArgsConstructor
public class ActionDto {
    private List<Command> commands;

    public ActionDto(List<Command> commands) {
        this.commands = commands;
    }
}
