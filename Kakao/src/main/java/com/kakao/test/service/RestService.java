package com.kakao.test.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.kakao.test.config.ApiInfo;
import com.kakao.test.config.ElevatorInfo;
import com.kakao.test.dto.ActionDto;
import com.kakao.test.dto.OnCallsDto;
import com.kakao.test.dto.StartDto;
import com.kakao.test.dto.component.Command;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@Service
public class RestService {
    private static int problemId = 0;
    private static int numberOfElevators = 4;
    @Autowired
    ElevatorInfo elevatorInfo;

    @Autowired
    ApiInfo apiInfo;

    @Autowired
    RestTemplate restTemplate;

    @Autowired
    ObjectMapper objectMapper;

    public OnCallsDto getOnCalls(String authCode) {
        HttpHeaders headers = new HttpHeaders();
        headers.set("Accept", MediaType.APPLICATION_JSON_VALUE);
        headers.set("X-Auth-Token", authCode);

        HttpEntity<OnCallsDto> onCallsDtoEntity = restTemplate.exchange(
                apiInfo.base + apiInfo.oncalls,
                HttpMethod.GET,
                new HttpEntity<>(headers),
                OnCallsDto.class);
        OnCallsDto onCallsDto = onCallsDtoEntity.getBody();
        System.out.println(onCallsDto);
        return onCallsDto;
    }


    public StartDto actionForServer(ActionDto actionDto, String token) {
        HttpHeaders headers = new HttpHeaders();
        headers.set("Accept", MediaType.APPLICATION_JSON_VALUE);
        headers.set("X-Auth-Token", token);

        HttpEntity<?> entity = null;
        try {
            String commandBody = objectMapper.writeValueAsString(actionDto);
            System.out.println(commandBody);
            entity = new HttpEntity<>(commandBody, headers);
        } catch (JsonProcessingException e) {
            e.printStackTrace();
        }

        HttpEntity<StartDto> startDtoEntity = restTemplate.exchange(
                apiInfo.base + apiInfo.actions,
                HttpMethod.POST,
                entity,
                StartDto.class
        );
        StartDto startDto = startDtoEntity.getBody();
        System.out.println(startDto);
        return startDto;
    }

    // /start/{user_key}/{problem_id}/{number_of_elevators}
    @Async
    public StartDto startForServer(int idx) {
        HttpHeaders headers = new HttpHeaders();
        headers.set("Accept", MediaType.APPLICATION_JSON_VALUE);
        HttpEntity<?> entity = new HttpEntity<>(headers);
        HttpEntity<StartDto> startDtoEntity = restTemplate.exchange(apiInfo.base + apiInfo.start,
                HttpMethod.POST,
                entity,
                StartDto.class,
                apiInfo.userKey,
                problemId,
                numberOfElevators
        );
        StartDto startDto = startDtoEntity.getBody();
        apiInfo.setAuthCode(startDto.getToken());
        System.out.println(idx + " " + startDto + " ");
        return startDto;
    }

}
