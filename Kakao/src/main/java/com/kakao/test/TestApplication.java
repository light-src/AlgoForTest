package com.kakao.test;

import com.kakao.test.config.ApiInfo;
import com.kakao.test.dto.ActionDto;
import com.kakao.test.dto.StartDto;
import com.kakao.test.dto.component.Command;
import com.kakao.test.service.RestService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.util.ArrayList;
import java.util.List;

@SpringBootApplication
public class TestApplication implements CommandLineRunner {

    public static void main(String[] args) {
        SpringApplication.run(TestApplication.class, args);
    }

    @Autowired
    RestService restService;

    @Override
    public void run(String... args) throws Exception {
        for (int i = 0; i < 30; i++) {
            StartDto startDto = restService.startForServer(i);
        }
//        String authToken = startDto.getToken();
/*
        restService.getOnCalls(authToken);
        List<Command> commands = new ArrayList<>();
        for(int commandIdx = 0 ; commandIdx < 4; commandIdx++){
            Command command = new Command();
            command.setCommand("STOP");
            command.setElevatorId(commandIdx);
            commands.add(command);
        }
        restService.actionForServer(new ActionDto(commands), authToken);*/
//        restService.commandForServer();
    }
}
