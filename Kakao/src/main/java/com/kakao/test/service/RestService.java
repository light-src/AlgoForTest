package com.kakao.test.service;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.kakao.test.config.ApiInfo;
import com.kakao.test.config.ElevatorInfo;
import com.kakao.test.dto.OnCallsDto;
import com.kakao.test.dto.StartDto;
import com.kakao.test.dto.component.Command;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
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

    public void getOncCalls(){
        HttpHeaders headers = new HttpHeaders();
        headers.set("Accept", MediaType.APPLICATION_JSON_VALUE);
        headers.set("X-Auth-Token", apiInfo.getAuthCode());
         HttpEntity<OnCallsDto> onCallsDtoEntity = restTemplate.exchange(
                 apiInfo.base + apiInfo.oncalls, OnCallsDto.class);
        System.out.println(onCallsDtoEntity.getBody());
    }


    public void commandForServer(List<Command> commands){
        HttpHeaders headers = new HttpHeaders();
        headers.set("Accept", MediaType.APPLICATION_JSON_VALUE);
        headers.set("X-Auth-Token", apiInfo.getAuthCode());

        HttpEntity<?> entity = null;
        try {
            entity = new HttpEntity<>(objectMapper.writeValueAsString(commands), headers);
        } catch (JsonProcessingException e) {
            e.printStackTrace();
        }
        HttpEntity<StartDto> starDto = restTemplate.exchange(apiInfo.base + apiInfo.start,
                HttpMethod.POST,
                entity,
                StartDto.class,
                apiInfo.userKey,
                problemId,
                numberOfElevators
        );
        System.out.println(starDto);
    }

    // /start/{user_key}/{problem_id}/{number_of_elevators}
    public void startForServer(){
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
        System.out.println(startDto);
    }

}
